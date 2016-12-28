#ifndef JNHELPER_H
#define JNHELPER_H

#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

class JNHelper : public QObject
{
    Q_OBJECT
public:
    explicit JNHelper(QObject *parent = 0);

public:
    static void AutoRunWithSystem(bool IsAutoRun, QString AppName, QString AppPath);
    static void SetUTF8Code();
    static void SetStyle(const QString &qssFile);
    static void SetChinese();
    static bool IsIP(QString IP);
    static QString ShowInputBox(QString info, bool &ok);
    static void ShowMessageBoxInfo(QString info);
    static void ShowMessageBoxError(QString info);
    static int ShowMessageBoxQuesion(QString info);
    static void Sleep(int sec);
    static void FormInCenter(QWidget *frm);

signals:

public slots:
};

#endif // JNHELPER_H
