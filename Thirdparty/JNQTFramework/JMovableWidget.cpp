﻿/****************************************************************************
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

#include "JMovableWidget.h"


namespace JNQTF
{

JMovableWidget::JMovableWidget(QWidget *parent) :
    QFrame(parent)
{
}


void JMovableWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
    }
    e->accept();
}


void JMovableWidget::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    e->accept();
}

void JMovableWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(leftbuttonpressed)
    {
        move(e->globalPos() - dragPosition);
    }
    e->accept();
}

}   //namespace JNQTF
