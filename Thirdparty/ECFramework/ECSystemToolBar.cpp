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

#include <QHBoxLayout>
#include <QDir>
#include "ECConfig.h"
#include "ECSystemToolBar.h"

namespace ECFramework
{


ECSystemToolBar* ECSystemToolBar::m_instance = NULL;

ECSystemToolBar::ECSystemToolBar(QWidget *parent)
    :QFrame(parent)
{
    setObjectName(QString("ECSystemToolBar"));

    initData();
    initUI();
    initConnect();
    m_fixButton->click();
}

ECSystemToolBar* ECSystemToolBar::getInstace(QWidget *parent)
{
    if(!m_instance)
    {
        m_instance = new ECSystemToolBar(parent);
    }
    return m_instance;
}

void ECSystemToolBar::initData()
{
    m_refreshButton = new ECToolButton(this);
    m_refreshButton->setFocusPolicy(Qt::NoFocus);

    m_settingButton = new ECToolButton(this);
    m_settingButton->setFocusPolicy(Qt::NoFocus);

    m_fixButton = new ECToolButton(this);
    m_fixButton->setFocusPolicy(Qt::NoFocus);

    m_minButton = new ECToolButton(this);
    m_minButton->setFocusPolicy(Qt::NoFocus);

    m_maxButton = new ECToolButton(this);
    m_maxButton->setFocusPolicy(Qt::NoFocus);

    m_closeButton = new ECToolButton(this);
    m_closeButton->setFocusPolicy(Qt::NoFocus);

    m_normal_max_flag = true;
    m_fixflag = false;
}

void ECSystemToolBar::initUI()
{
    SetBarHeight(EC_SYSTEMTOOLBAR_HEIGHT);

    QString qssstr = QLatin1String("QToolButton{\
                                   background-color: transparent;\
                                   color: white;\
                               }\
                               QToolButton:hover{\
                                   background-color: red;\
                                   border: 1px;\
                               }");

    m_closeButton->setStyleSheet(qssstr);

    //QString apppath = QDir::currentPath();

    SetRefreshButton(":/image/ui/icons/dark/appbar.refresh.png");
    SetSettingButton(":/image/ui/icons/dark/appbar.control.down.png");
    SetFixButton(":/image/ui/icons/dark/appbar.lock.png",
                 ":/image/ui/icons/dark/appbar.unlock.keyhole.png");
    SetMinButton(":/image/ui/icons/dark/appbar.minus.png");
    SetMaxButton(":/image/ui/icons/dark/appbar.app.png",
                 ":/image/ui/icons/dark/appbar.fullscreen.box.png");
    SetCloseButton(":/image/ui/icons/dark/appbar.close.png");

    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addWidget(m_refreshButton);
    mainlayout->addWidget(m_settingButton);
    mainlayout->addWidget(m_fixButton);
    mainlayout->addWidget(m_minButton);
    mainlayout->addWidget(m_maxButton);
    mainlayout->addWidget(m_closeButton);
    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void ECSystemToolBar::initConnect()
{
    connect(m_refreshButton, SIGNAL(clicked()), this, SIGNAL(refreshed()));

    connect(m_settingButton, SIGNAL(clicked()), m_settingButton, SLOT(showMenu()));

    connect(m_fixButton, SIGNAL(clicked()), this, SLOT(changeFix()));

    connect(m_maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(m_minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(m_closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));

    connect(m_maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

bool ECSystemToolBar::GetFixedflag()
{
    return m_fixflag;
}

void ECSystemToolBar::SetBarHeight(int height)
{
    setFixedHeight(height);
    m_refreshButton->setIconSize(QSize(height, height));
    m_settingButton->setIconSize(QSize(height, height));
    m_fixButton->setIconSize(QSize(height, height));
    m_minButton->setIconSize(QSize(height, height));
    m_maxButton->setIconSize(QSize(height, height));
    m_closeButton->setIconSize(QSize(height, height));
}

void ECSystemToolBar::SetSettingMenu(QMenu* menu)
{
    m_settingButton->SetButtonMenu(menu);
}


void ECSystemToolBar::SetRefreshButton(QString imgpath)
{
    m_refreshButton->setIcon(QIcon(imgpath));
    m_refreshButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetRefreshButton()
{
    return m_refreshButton;
}

void ECSystemToolBar::SetRefreshButtonVisible(bool visible)
{
    m_refreshButton->setVisible(visible);
}

bool ECSystemToolBar::IsRefreshButtonVisible()
{
    return m_refreshButton->isVisible();
}

void ECSystemToolBar::SetSettingButton(QString imgpath)
{
    m_settingButton->setIcon(QIcon(imgpath));
    m_settingButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetSettingButton()
{
    return m_settingButton;
}


void ECSystemToolBar::SetSettingButtonVisible(bool visible)
{
    m_settingButton->setVisible(visible);
}

bool ECSystemToolBar::IsSettingButtonVisible()
{
    return m_settingButton->isVisible();
}


void ECSystemToolBar::SetFixButton(QString fimgpath, QString ufimgpath)
{
    m_fixbtn_fimgpath = fimgpath;
    m_fixbtn_ufimgpath = ufimgpath;
    m_fixButton->setIcon(QIcon(fimgpath));
    m_fixButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetFixButton()
{
    return m_fixButton;
}

void ECSystemToolBar::SetFixButtonVisible(bool visible)
{
    m_fixButton->setVisible(visible);
}

bool ECSystemToolBar::IsFixButtonVisible()
{
    return m_fixButton->isVisible();
}


void ECSystemToolBar::SetMinButton(QString imgpath)
{
    m_minButton->setIcon(QIcon(imgpath));
    m_minButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetMinButton()
{
    return m_minButton;
}

void ECSystemToolBar::SetMinButtonVisible(bool visible)
{
    m_minButton->setVisible(visible);
}

bool ECSystemToolBar::IsMinButtonVisible()
{
    return m_minButton->isVisible();
}


void ECSystemToolBar::SetMaxButton(QString nimgpath, QString mimgpath)
{
    m_maxbtn_nimgpath = nimgpath;
    m_maxbtn_mimgpath = mimgpath;
    m_maxButton->setIcon(QIcon(nimgpath));
    m_maxButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetMaxButton()
{
    return m_maxButton;
}

void ECSystemToolBar::SetMaxButtonVisible(bool visible)
{
    m_maxButton->setVisible(visible);
}

bool ECSystemToolBar::IsMaxButtonVisible()
{
    return m_maxButton->isVisible();
}


void ECSystemToolBar::SetCloseButton(QString imgpath)
{
    m_closeButton->setIcon(QIcon(imgpath));
    m_closeButton->setIconSize(QSize(height(), height()));
}

ECToolButton* ECSystemToolBar::GetCloseButton()
{
    return m_closeButton;
}

void ECSystemToolBar::SetCloseButtonVisible(bool visible)
{
    m_closeButton->setVisible(visible);
}

bool ECSystemToolBar::IsCloseButtonVisible()
{
    return m_closeButton->isVisible();
}




void ECSystemToolBar::switchMaxMin()
{
    if(m_normal_max_flag)
    {
        m_maxButton->setIcon(QIcon(m_maxbtn_mimgpath));
        m_maxButton->setIconSize(QSize(height(), height()));
        m_normal_max_flag = false;
    }
    else{
        m_maxButton->setIcon(QIcon(m_maxbtn_nimgpath));
        m_maxButton->setIconSize(QSize(height(), height()));
        m_normal_max_flag = true;
    }
}

void ECSystemToolBar::clearChecked()
{
    m_settingButton->setChecked(false);
    m_fixButton->setChecked(false);
    m_minButton->setChecked(false);
    m_maxButton->setChecked(false);
    m_closeButton->setChecked(false);
}

void ECSystemToolBar::changeFix()
{
    if(m_fixflag)
    {
        m_fixButton->setIcon(QIcon(m_fixbtn_fimgpath));
        m_fixButton->setIconSize(QSize(height(), height()));
    }
    else{
        m_fixButton->setIcon(QIcon(m_fixbtn_ufimgpath));
        m_fixButton->setIconSize(QSize(height(), height()));
    }
    m_fixflag = !m_fixflag;

    emit fixchanged(m_fixflag);
}



}   //namespace ECFramework
