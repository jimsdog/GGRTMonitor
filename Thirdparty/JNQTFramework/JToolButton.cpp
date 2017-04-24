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

#include "JToolButton.h"
#include<QCursor>
#include <QDebug>


namespace JNQTF
{


JToolButton::JToolButton(QWidget* parent) :
   QToolButton(parent)
{

}

void JToolButton::setMenu(QMenu *menu){
    connect(menu, SIGNAL(aboutToHide()), this, SLOT(recover()));
    QToolButton::setMenu(menu);
}


void JToolButton::recover(){
    #ifdef Q_OS_LINUX
        bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
        this->setAttribute(Qt::WA_UnderMouse, flag);
        this->update();
    #endif
}

JToolButton::~JToolButton()
{

}

}   //namespace JNQTF

