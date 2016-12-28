#ifndef JNQTLOGGER_H
#define JNQTLOGGER_H

#include <QtCore>
#include "QSettings"
#include <QString>
#include <Qthread>
#include <QTextStream>
#include <QMutex>


class JNQTLogger
{
private:
    JNQTLogger();

public:
    static QString LogFileName;             //应用程序路径
    static QMutex Mtx;

    static void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    static void SetUpLogger();
    static void UnSetLogger();

    static void test();

};

#endif // JNQTLOGGER_H
