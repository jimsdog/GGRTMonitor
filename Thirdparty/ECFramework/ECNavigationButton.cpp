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

#include "ECConfig.h"
#include "ECNavigationButton.h"

namespace ECFramework
{

ECNavigationButton::ECNavigationButton(QWidget *parent)
    :QPushButton(parent)
{
    setObjectName("ECNavigationButton");
}

void ECNavigationButton::Init(QString imgpath, QString title)
{
    m_imgpath = imgpath;
    m_title = title;

    initData();
    initUI();
    initConnect();
}

void ECNavigationButton::initData()
{

}

void ECNavigationButton::initUI()
{
    //border-image: url(%1);
    //background-image: url(%1);
    QString qssstr = QLatin1String("QPushButton{ \
                                   background-image: url(%1);\
                                   background-repeat:no-repeat;\
                                   background-position: center bottom;\
                                   background-color: transparent;\
                                   color: white;\
                                   text-align: center bottom;\
                                   padding-bottom: 2px;\
                               }\
                               QPushButton:hover{\
                                   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 82, 112, 255), stop:0.5 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                                   color: white;\
                                   border: 0px solid rgb(255, 127, 39);\
                               }\
                               QPushButton:checked{\
                                   background-color: rgb(0, 82, 112);\
                                   color: white;\
                                   border: 0px solid rgb(255, 127, 39);\
                               }\
                               QPushButton:flat{\
                                   border: none;\
                               }");

    setStyleSheet(qssstr.arg(m_imgpath));
    setFlat(true);
    setCheckable(true);
    setFixedSize(EC_NAVIGATIONBUTTON_WIDTH, EC_TITLEBAR_HEIGHT);
    setText(m_title);
    setFocusPolicy(Qt::NoFocus);
}

void ECNavigationButton::initConnect()
{

}

}   //namespace ECFramework
