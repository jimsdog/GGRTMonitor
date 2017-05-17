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

#include "ECConfig.h"
#include "ECMainWindow.h"
#include "ECSettingMenu.h"

#include "ECLoading.h"
#include "ECWaitDialog.h"

#include "ECSpeech.h"

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
    m_pstatusbar = new QStatusBar(this);
    m_settingmenu = new ECSettingMenu(this);

    m_leftbuttonpressed = false;
    m_lockmoved = false;
    m_locked = false;

    m_speech = new ECSpeech(this);
}

void ECMainWindow::initUI()
{
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("GGRTMonitor");

    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    setMinimumSize(desktopWidget->availableGeometry().size()* 0.6);
    resize(desktopWidget->availableGeometry().size()* 0.8);


    m_pstatusbar->setFixedHeight(EC_STATUSBAR_HEIGHT);
    setStatusBar(m_pstatusbar);

    QString apppath = QDir::currentPath();
    //QString appimgpath = apppath + "/Images/logogoogol.png";
    //QString title = QString::fromLocal8Bit("重庆固高");
    QString appimgpath = apppath + "/Images/yglogo.png";
    QString title = QString::fromLocal8Bit("远哥智慧餐饮系统");

    //setting->setFixedSize(500,600);

    ECLoading *mainpage = new ECLoading(this);
    mainpage->Init(apppath + "/LocalRes/ui/loading.html");
    //mainpage->setFixedSize(500,600);

    QFrame *viewpage = new QFrame(this);

    QFrame *reportpage = new QFrame(this);

    QFrame *setting = new QFrame(this);

    m_settingmenu->Init(this);

    //m_mainframe->GetFlyWidget()->Init(":/image/ui/robot128X128.ico", m_settingmenu);
    m_mainframe->GetFlyWidget()->Init(":/image/ui/yglogo128X128.ico", m_settingmenu);
    m_mainframe->GetQSystemTrayIcon()->setContextMenu(m_settingmenu);
    m_mainframe->GetAppBar()->SetSystemToolSettingMenu(m_settingmenu);

    m_mainframe->SetLogo(appimgpath, title);
    m_mainframe->AddNavgation(":/image/ui/icons/dark/appbar.os.windows.8.png", QString::fromLocal8Bit("主屏"), mainpage);
    m_mainframe->AddNavgation(":/image/ui/icons/dark/appbar.home.png", QString::fromLocal8Bit("站点"), viewpage);
    m_mainframe->AddNavgation(":/image/ui/icons/dark/appbar.graph.bar.png", QString::fromLocal8Bit("报表"), reportpage);
    m_mainframe->AddNavgation(":/image/ui/icons/dark/appbar.cog.png", QString::fromLocal8Bit("设置"), setting);
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

    connect(m_mainframe->GetAppBar(), SIGNAL(refreshed()), this, SLOT(refreshAction()));

    connect(m_mainframe->GetQSystemTrayIcon(), SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));

    connect(m_mainframe->GetFlyWidget(), SIGNAL(showmainwindow()), this, SLOT(showMainWindow()));
}

QStatusBar* ECMainWindow::GetStatusBar()
{
    return m_pstatusbar;
}

void ECMainWindow::showMainWindow()
{
    if(isHidden())
    {
        //恢复窗口显示
        show();
        //一下两句缺一均不能有效将窗口置顶
        //setWindowState(Qt::WindowActive);
        //activateWindow();

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
                //setWindowState(Qt::WindowActive);
                //activateWindow();

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
    m_mainframe->GetQSystemTrayIcon()->deleteLater();
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
        m_mainframe->GetAppBar()->GetSystemToolBar()->switchMaxMin();
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

void ECMainWindow::refreshAction()
{
    /*ECWaitDialog *wdlg = new ECWaitDialog(this);
    wdlg->show();*/

    QString text = QString::fromLocal8Bit("测试语音提示消息！");
    //m_speech->say(text);

    m_speech->tell(text);

    //m_speech->tell(text, this, SLOT(close()));
}

}   //namespace ECFramework
