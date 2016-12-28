#include "jnqtlogger.h"




QString JNQTLogger::LogFileName = "log.txt";

QMutex JNQTLogger::Mtx;



JNQTLogger::JNQTLogger()
{

}

void JNQTLogger::myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Mtx.lock();
    try{
        QString typeMsg;
        switch (type) {
        case QtDebugMsg:
            typeMsg = QString("Debug");
            break;
        case QtInfoMsg:
            typeMsg = QString("Info");
            break;
        case QtWarningMsg:
            typeMsg = QString("Warning");
            break;
        case QtCriticalMsg:
            typeMsg = QString("Critical");
            break;
        case QtFatalMsg:
            typeMsg = QString("Fatal");
            //abort();
        }

        QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
        QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
        QString current_date = QString("(%1)").arg(current_date_time);
        QString message = QString("%1 %2 %3 %4").arg(typeMsg).arg(context_info).arg(msg).arg(current_date);

        //QString logFilePath = QDir::currentPath() + LogFileName;
        QString logFilePath = LogFileName;
        QFile file(logFilePath);
        file.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream text_stream(&file);
        text_stream << message << "\r\n";
        file.flush();
        file.close();
    }
    catch(const char* )
    {
    }
    Mtx.unlock();
}

void JNQTLogger::test()
{
    QString message = "text";
    //QString logFilePath = QDir::currentPath() + LogFileName;
    QString logFilePath = LogFileName;
    QFile file(logFilePath);
    //file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
}

void JNQTLogger::SetUpLogger()
{
    qInstallMessageHandler(JNQTLogger::myMessageOutput);
}

void JNQTLogger::UnSetLogger()
{
    qInstallMessageHandler(0);
}

