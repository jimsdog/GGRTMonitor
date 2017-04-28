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
#include "ECAppBar.h"

namespace ECFramework
{

ECAppBar* ECAppBar::m_instance = NULL;

ECAppBar::ECAppBar(QWidget *parent)
    :QFrame(parent)
{
    setObjectName(QString("ECAppBar"));

    initData();
    initUI();
    initConnect();
}

ECAppBar* ECAppBar::getInstace(QWidget *parent)
{
    if(!m_instance)
    {
        m_instance = new ECAppBar(parent);
    }
    return m_instance;
}

void ECAppBar::initData()
{
    m_mainlayout = new QVBoxLayout(this);
    m_systemtoolbar = ECSystemToolBar::getInstace(this);
}

void ECAppBar::initUI()
{
    setFixedHeight(EC_TITLEBAR_HEIGHT);
    if(!m_mainlayout || !m_systemtoolbar)
    {
        return;
    }
    m_mainlayout->addWidget(m_systemtoolbar);
    m_mainlayout->addStretch();
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->setSpacing(0);
    setLayout(m_mainlayout);
}

void ECAppBar::initConnect()
{

}

void ECAppBar::SetSystemToolSettingMenu(QMenu* menu)
{
    m_systemtoolbar->SetSettingMenu(menu);
}

}   //namespace ECFramework
