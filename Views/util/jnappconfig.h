#ifndef JNAPPCONFIG_H
#define JNAPPCONFIG_H


class QString;

class JNAppConfig
{
private:
    JNAppConfig();

public:
    static QString AppPath;             //应用程序路径
    static int AppFontSize;             //应用程序字体大小
    static QString AppFontName;         //应用程序字体名称

    static QString VideoType;           //当前画面展示类型

    static void ReadConfig();           //读取配置文件,在main函数最开始加载程序载入
    static void WriteConfig();          //写入配置文件,在更改配置文件程序关闭时调用

};

#endif // JNAPPCONFIG_H
