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
#include "ECNavigationBar.h"

namespace ECFramework
{

ECNavigationBar* ECNavigationBar::m_instance = NULL;

ECNavigationBar::ECNavigationBar(QWidget *parent) :
    QFrame(parent)
{
    setObjectName(QString("ECNavigationBar"));

    initData();
    initUI();
    initConnect();
}

ECNavigationBar* ECNavigationBar::getInstace(QWidget *parent)
{
    if(!m_instance)
    {
        m_instance = new ECNavigationBar(parent);
    }
    return m_instance;
}

void ECNavigationBar::initData()
{
    m_cIndex = 0;
}

void ECNavigationBar::initUI()
{

}

void ECNavigationBar::ResetLayout()
{
    //setFixedSize(QSize(EC_NAVIGATIONBUTTON_WIDTH*(GetCount() != 0? GetCount(): 1), EC_TITLEBAR_HEIGHT));
    m_navlayout = new QHBoxLayout(this);
    for(int i=0; i < m_buttons.length(); i++)
    {
        m_navlayout->addWidget(m_buttons.at(i));
    }
    m_navlayout->addStretch();
    m_navlayout->setContentsMargins(0, 0, 0, 0);
    m_navlayout->setSpacing(0);
    setLayout(m_navlayout);
}

void ECNavigationBar::initConnect()
{
    for(int i=0; i<m_buttons.length(); i++)
    {
        connect(m_buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
}

void ECNavigationBar::AddNavgationButton(QString imgpath, QString title)
{
    if(GetCount() >= EC_NAVIGATIONBUTTON_MAXCOUNT)
    {
        return;
    }
    m_buttonTitles  << title;
    ECNavigationButton* button = new ECNavigationButton(this);
    m_buttons.append(button);
    button->Init(imgpath, title);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

int ECNavigationBar::GetCurrentIndex()
{
    return m_cIndex;
}

void ECNavigationBar::SetCurrentIndex(int index)
{
    m_buttons.at(index)->click();
}

int ECNavigationBar::GetCount()
{
    return m_buttons.size();
}

void ECNavigationBar::setButtonChecked()
{
    for (int i = 0; i < m_buttons.size(); ++i) {
        if (m_buttons.at(i) == sender())
        {
            m_buttons.at(i)->setChecked(true);
            emit indexChanged(i);
            m_cIndex = i;
        }
        else{
            m_buttons.at(i)->setChecked(false);
        }
    }
}


}   //namespace ECFramework
