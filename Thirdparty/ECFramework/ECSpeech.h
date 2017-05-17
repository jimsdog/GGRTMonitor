/****************************************************************************
**
** Copyright (C) 2017 JIMSDOG
**
** ECFramework is a frameworke based on Qt5.3, you will be more efficient with it.
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


#ifndef __ECSPEECH_H__
#define __ECSPEECH_H__

#include <QObject>

namespace ECFramework
{

class ECSpeech : public QObject
{
    Q_OBJECT
public:
    struct Error
    {
        QString msg;
        Error(QString s):msg(s) {}
    };
    struct InitError : Error
    {
        InitError(QString s):Error(s) {}
    };
    struct LogicError : Error
    {
        LogicError(QString s):Error(s) {}
    };
    struct CloseError : Error
    {
        CloseError(QString s):Error(s) {}
    };

public:
    struct VoiceName
    {
        QString id;
        QString name;
    };
    typedef QList<VoiceName> VoiceNames;
public:
    explicit ECSpeech(QObject *parent = 0);
    ECSpeech(VoiceName n = VoiceName(), QObject * parent =0L);
    virtual ~ECSpeech();

public:
    const VoiceName & name() const;
    static VoiceNames voices();

    void say(QString) const;
    void tell(QString) const;
    void tell(QString, QObject * obj, const char * slot) const;

signals:
    void finished();

protected:
    virtual void timerEvent(QTimerEvent *);

private:
    class Private;
    Private * d;
};

}   //namespace ECFramework

#endif // __ECSPEECH_H__
