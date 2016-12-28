#include "jnappconfig.h"

#include <QtCore>
#include "QSettings"


QString JNAppConfig::AppPath = "";
QString JNAppConfig::VideoType = "1_4";

#ifdef Q_OS_WIN
int JNAppConfig::AppFontSize = 10;
QString JNAppConfig::AppFontName = "Microsoft YaHei";
#endif

#ifdef Q_OS_LINUX
#ifdef __arm__
int JNAppConfig::AppFontSize = 11;
QString JNAppConfig::AppFontName = "WenQuanYi Micro Hei";
#else
int JNAppConfig::AppFontSize = 11;
QString JNAppConfig::AppFontName = "WenQuanYi";
#endif
#endif

#ifdef Q_OS_MAC
int JNAppConfig::AppFontSize = 11;
QString JNAppConfig::AppFontName = "Heiti SC";
#endif


JNAppConfig::JNAppConfig()
{

}

void JNAppConfig::ReadConfig()
{
    JNAppConfig::AppPath = QDir::currentPath();

    JNAppConfig::VideoType = "1_4";

    //QString cfgFileName = JNAppConfig::AppPath + "config.cfg";



    QString fileName = JNAppConfig::AppPath + "config.txt";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup("AppConfig");
    set->endGroup();
}

void JNAppConfig::WriteConfig()
{
    QString fileName = JNAppConfig::AppPath + "config.txt";
    QSettings *set = new QSettings(fileName, QSettings::IniFormat);
    set->beginGroup("AppConfig");
    set->endGroup();
}
