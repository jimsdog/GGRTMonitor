/****************************************************************************
**
** Copyright (C) 2017 JIMSDOG
**
** JNQTFramework is a frameworke based on Qt5.3, you will be more efficient with it.
**
** Version	: 0.0.1.0
** Author	: Jimsdog
** Website	: https://github.com/jimsdog
** Project	: https://github.com/jimsdog/GGRTMonitor
** Blog		: http://www.jimsdog.com
** Wiki		: https://github.com/jimsdog/GGRTMonitor/wiki
** Lincence: LGPL V2
** QQ: 363280425
** Email: jims@jimsdog.com  mr.oldbig@gmail.com  jims.007007@163.com
**
****************************************************************************/

#include "JUtil.h"


namespace JNQTF
{

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
    {
        QByteArray localMsg = msg.toLocal8Bit();
        QString outmsg;

        switch (type) {
            case QtDebugMsg:
                fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
                outmsg = QString("Debug: %1 %2 %3 %4\r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
                break;
            case QtWarningMsg:
                fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
                outmsg = QString("Warning: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
                break;
            case QtCriticalMsg:
                fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
                outmsg = QString("Critical: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
                break;
            case QtFatalMsg:
                fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
                outmsg = QString("Fatal: %1 %2 %3 %4 \r\n").arg(localMsg.constData(), context.file, QString(context.line), context.function);
                abort();
        }

        QFile outFile("debuglog.txt");
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts << outmsg <<endl;
    }

void loadFonts(QApplication& app) {
    QFontDatabase database;
    QStringList fontlist = database.families();

    QStringList preferList;
//    preferList.append("Microsoft YaHei UI");
//    preferList.append("微软雅黑");
    preferList.append("SimSong");
    preferList.append("宋体");
    preferList.append("WenQuanYi Micro Hei");
    preferList.append("文泉驿微米黑");

    foreach (QString font, preferList) {
        if (fontlist.contains(font)) {
            app.setFont(QFont(font));
            qDebug()<<&app<<" set font: "<<font;
            return;
        }
    }
}
#endif



QString getQssFromFile(QString filename)
{
    QFile f(filename);
    QString qss = "";
    if (f.open(QFile::ReadOnly))
    {
        qss = QLatin1String(f.readAll());
        f.close();
    }
    return qss;
};

QString readFile(const QString filename)
{
    QFile f(filename);
    if (!f.open(QFile::ReadOnly | QFile::Text)) {
        return QString();
    } else {
        QTextStream in(&f);
        return in.readAll();
    }
}


void setSkinForApp(QString filename)
{
    QString qss = getQssFromFile(filename);
    qApp->setStyleSheet(qss);
}

}   //namespace JNQTF
