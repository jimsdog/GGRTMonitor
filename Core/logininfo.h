#ifndef LOGININFO_H
#define LOGININFO_H


#include <Ice/Ice.h>
#include <IceUtil/IceUtil.h>

class LoginInfo : public IceUtil::Shared
{
public:
    LoginInfo();

public:
    std::string username() const;
    void setUsername(const std::string& username);

    std::string password() const;
    void setPassword(const std::string& password);

    void load();
    void save();

private:

    IceUtil::Mutex _mutex;
    std::string _username;
    std::string _password;
};

typedef IceUtil::Handle<LoginInfo> LoginInfoPtr;

#endif // LOGININFO_H
