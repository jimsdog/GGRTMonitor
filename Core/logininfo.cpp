#include "logininfo.h"
#include "ggcommdefine.h"
#include <QSettings>

#include <string>
#include <vector>

using namespace std;

LoginInfo::LoginInfo()
{

}

std::string LoginInfo::username() const
{
    IceUtil::Mutex::Lock sync(_mutex);
    return _username;
}

void LoginInfo::setUsername(const std::string& username)
{
    IceUtil::Mutex::Lock sync(_mutex);
    _username = username;
}

std::string LoginInfo::password() const
{
    IceUtil::Mutex::Lock sync(_mutex);
    return _password;
}

void LoginInfo::setPassword(const std::string& password)
{
    IceUtil::Mutex::Lock sync(_mutex);
    _password = password;
}

void LoginInfo::load()
{
    IceUtil::Mutex::Lock sync(_mutex);
#ifdef _WIN32
    QString envUserName;
    vector<wchar_t> v(256);
    DWORD ret = GetEnvironmentVariableW(L"USERNAME", &v[0], static_cast<DWORD>(v.size()));
    if(ret >= v.size())
    {
        v.resize(ret + 1);
        ret = GetEnvironmentVariableW(L"USERNAME", &v[0], static_cast<DWORD>(v.size()));
    }

    if(ret > 0)
    {
        envUserName = QString::fromUtf16(reinterpret_cast<ushort*>(&v[0]), ret);
    }
    else
    {
        envUserName = "";
    }
#else
    QString envUserName(getenv("USER"));
#endif
    QSettings settings(ORGANIZATION, APPLICATION);
    settings.beginGroup("LoginInfo");
    _username = settings.value("username", envUserName).toString().toUtf8().data();
    settings.endGroup();
}

void LoginInfo::save()
{
    IceUtil::Mutex::Lock sync(_mutex);
    QSettings settings(ORGANIZATION, APPLICATION);
    settings.beginGroup("LoginInfo");
    settings.setValue("username", _username.c_str());
    settings.endGroup();
    settings.sync();
}
