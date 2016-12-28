#ifndef JNICONHELPER_H
#define JNICONHELPER_H

#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

class JNIconHelper : public QObject
{
    Q_OBJECT
private:
    explicit JNIconHelper(QObject *parent = 0);

private:
    QFont iconFont;
    static JNIconHelper *_instance;

public:
    static JNIconHelper *Instance();
    void SetIcon(QLabel *lab, QChar c);
    void SetIcon(QPushButton *btn, QChar c);

signals:

public slots:
};

#endif // JNICONHELPER_H
