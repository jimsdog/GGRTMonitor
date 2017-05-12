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

#include <QDir>
#include <QContextMenuEvent>
#include "ECLoading.h"

namespace ECFramework
{

ECLoading::ECLoading(QWidget *parent)
    :QWebEngineView(parent)
{
    setObjectName("ECLoading");
}

void ECLoading::contextMenuEvent(QContextMenuEvent *event)
{
    if(event->reason() == QContextMenuEvent::Mouse)
    {
        event->accept();
    }
}

void ECLoading::initData()
{

}

void ECLoading::initUI()
{
    QUrl url = QUrl::fromLocalFile(m_htmlpath);
    setUrl(url);
}

void ECLoading::initConnect()
{

}

void ECLoading::Init(QString htmlpath)
{
    m_htmlpath = htmlpath;

    initData();
    initUI();
    initConnect();
}

}   //namespace ECFramework
