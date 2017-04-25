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

#ifndef __JMovableWidget_H__
#define __JMovableWidget_H__

#include <QFrame>
#include <QMouseEvent>


namespace JNQTF
{

class JMovableWidget : public QFrame
{
    Q_OBJECT
private:
    QPoint dragPosition;
    bool leftbuttonpressed;
protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

public:
    explicit JMovableWidget(QWidget *parent = 0);

signals:

public slots:

};

}   //namespace JNQTF

#endif // __JMovableWidget_H__
