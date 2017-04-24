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

#ifndef __JWigglyWidget_H__
#define __JWigglyWidget_H__

#include <QBasicTimer>
#include <QWidget>
#include <QLabel>
#include <QTimerEvent>
#include <QPainter>

namespace JNQTF
{

class JWigglyWidget : public QLabel
{
    Q_OBJECT

public:
    JWigglyWidget(const QString &text, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    QBasicTimer timer;
    QString text;
    int step;
};

}   //namespace JNQTF


#endif // __JWigglyWidget_H__
