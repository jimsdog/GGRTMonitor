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

#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>

#include "ECMainWindow.h"
#include "ECSettingMenu.h"

namespace ECFramework
{

ECMainWindow::ECMainWindow(QWidget *parent) : QMainWindow(parent)
{
    setObjectName(QString("ECMainWindow"));

    initData();
    initUI();
    initConnect();
}

void ECMainWindow::initData()
{
    m_mainframe = ECMainFrame::getInstace(this);
    m_settingmenu = new ECSettingMenu(this);

    m_leftbuttonpressed = false;
    m_lockmoved = false;
    m_locked = false;
}

void ECMainWindow::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("GGRTMonitor");

    QString apppath = QDir::currentPath();
    QString appimgpath = apppath + "/Images/logogoogol.png";
    QString title = QString::fromLocal8Bit("重庆固高");

    QFrame *setting = new QFrame(this);
    //setting->setFixedSize(500,600);

    QFrame *mainpage = new QFrame(this);
    //mainpage->setFixedSize(500,600);

    m_settingmenu->Init(this);

    m_mainframe->GetFlyWidget()->Init(":/image/ui/robot128X128.ico", m_settingmenu);
    m_mainframe->GetQSystemTrayIcon()->setContextMenu(m_settingmenu);
    m_mainframe->GetAppBar()->SetSystemToolSettingMenu(m_settingmenu);

    m_mainframe->SetLogo(appimgpath, title);
    m_mainframe->AddNavgation(apppath + "/Images/icons/dark/appbar.home.png", QString::fromLocal8Bit("主屏"), mainpage);
    m_mainframe->AddNavgation(apppath + "/Images/icons/dark/appbar.cog.png", QString::fromLocal8Bit("设置"), setting);
    m_mainframe->ResetNavgationLayout();

    m_mainframe->GetNavgationBar()->SetCurrentIndex(0);

    QVBoxLayout* mainvlayout = new QVBoxLayout(this);
    mainvlayout->addWidget(m_mainframe);
    mainvlayout->setContentsMargins(0, 0, 0, 0);
    mainvlayout->setSpacing(0);
    setLayout(mainvlayout);
}

void ECMainWindow::initConnect()
{
    connect(m_mainframe->GetAppBar(), SIGNAL(minimuned()), this, SIGNAL(Hidden()));
    connect(m_mainframe->GetAppBar(), SIGNAL(minimuned()), this, SLOT(hide()));
    connect(m_mainframe->GetAppBar(), SIGNAL(minimuned()), this, SLOT(showFlyWidget()));

    connect(m_mainframe->GetAppBar(), SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));

    connect(m_mainframe->GetAppBar(), SIGNAL(closed()), this, SIGNAL(Hidden()));
    connect(m_mainframe->GetAppBar(), SIGNAL(closed()), this, SLOT(hide()));
    connect(m_mainframe->GetAppBar(), SIGNAL(closed()), this, SLOT(showFlyWidget()));

    connect(m_mainframe->GetQSystemTrayIcon(), SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));

    connect(m_mainframe->GetFlyWidget(), SIGNAL(showmainwindow()), this, SLOT(showMainWindow()));
}

void ECMainWindow::showMainWindow()
{
    if(isHidden())
    {
        //恢复窗口显示
        show();
        //一下两句缺一均不能有效将窗口置顶
        setWindowState(Qt::WindowActive);
        activateWindow();

        m_mainframe->GetFlyWidget()->hide();
    }
}

void ECMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
        {
        //单击
        case QSystemTrayIcon::Trigger:
            //双击
        case QSystemTrayIcon::DoubleClick:
            if(isHidden())
            {
                //恢复窗口显示
                show();
                //一下两句缺一均不能有效将窗口置顶
                setWindowState(Qt::WindowActive);
                activateWindow();

                m_mainframe->GetFlyWidget()->hide();
            }
            else
            {
                hide();
                showFlyWidget();
                emit Hidden();
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

void ECMainWindow::showFlyWidget()
{
    m_mainframe->GetFlyWidget()->show();
}

void ECMainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    m_mainframe->resize(size());
}

void ECMainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
}

void ECMainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}

void ECMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    m_leftbuttonpressed = false;
    m_mainframe->GetAppBar()->GetSystemToolBar()->clearChecked();
    e->accept();
}

void ECMainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(e->y() < m_mainframe->GetTopHeight() && e->x() < m_mainframe->GetTopWidth())
        {
            m_dragPosition = e->globalPos() - frameGeometry().topLeft();
            m_leftbuttonpressed = true;
        }
        else
        {
            m_leftbuttonpressed = false;
        }
    }
    e->accept();
}


void ECMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {
        if(e->y() < m_mainframe->GetTopHeight() && e->x() < m_mainframe->GetTopWidth())
        {
            if(m_leftbuttonpressed)
            {
                if(m_mainframe->GetAppBar()->GetSystemToolBar()->GetFixedflag())
                {
                    move(e->globalPos() - m_dragPosition);
                }
                e->accept();
            }
        }
        else
        {
            e->ignore();
        }
    }
}

void ECMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < m_mainframe->GetTopHeight() && e->x() < m_mainframe->GetTopWidth())
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void ECMainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}

void ECMainWindow::settingmenuShowAbout()
{

}

}   //namespace ECFramework
