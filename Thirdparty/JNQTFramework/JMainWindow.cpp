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

#include "JMainWindow.h"
#include "JUtil.h"
#include <QtCore>

#include <QMouseEvent>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QDir>

namespace JNQTF
{


JMainWindow::JMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug("mainwindow init");
    initData();
    initUI();
    initConnect();
}

void JMainWindow::initData()
{
    leftbuttonpressed = false;
    lockmoved = false;
    locked = false;
}

void JMainWindow::initUI()
{
    titleBar = JTitleBar::getInstace();

    setObjectName(QString("FMainWindow"));
    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());
    readSettings();

    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("QFramer");

    pstatusbar = new QStatusBar;
    pstatusbar->setFixedHeight(35);
    setStatusBar(pstatusbar);
    trayicon = new QSystemTrayIcon(QIcon(QString(":/images/skin/images/QFramer.ico")), this);
    trayicon->setObjectName(QString("trayicon"));
    trayicon->setToolTip(QString(qApp->applicationName()));
    trayicon->show();

    flyWidget = new JFlyWidget(this);
    flyWidget->move(desktopWidget->availableGeometry().width() * 0.8, desktopWidget->availableGeometry().height() *0.2);
}


void JMainWindow::initConnect( )
{
    connect(titleBar, SIGNAL(minimuned()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(closed()), this, SIGNAL(Hidden()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(minimuned()), this, SLOT(showFlyWidget()));
    connect(titleBar, SIGNAL(maximumed()), this, SLOT(swithMaxNormal()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(hide()));
    connect(titleBar, SIGNAL(closed()), this, SLOT(showFlyWidget()));
    connect(trayicon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
}


void JMainWindow::readSettings()
{
   QDesktopWidget* desktopWidget = QApplication::desktop();
   int w = desktopWidget->availableGeometry().width();
   int h = desktopWidget->availableGeometry().height();
   QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
   settings.beginGroup("FMainWindow");
   resize(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize());
   printf("%d\n" ,(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize().height()));
   printf("%d\n" ,(settings.value("size", QSize(w * 0.6, h * 0.6)).toSize().width()));
   move(settings.value("pos", QPoint(w * 0.2, h * 0.1)).toPoint());
   settings.endGroup();
}

void JMainWindow::writeSettings()
{
    QSettings settings(QDir::currentPath() + "/QFramer.ini", QSettings::IniFormat);
    qDebug(qPrintable(QDir::currentPath() + "/QFramer.ini"));
    settings.beginGroup("JMainWindow");
    settings.setValue("size", size());
    settings.setValue("pos", pos());
    settings.endGroup();
}

bool JMainWindow::isMoved()
{
    return lockmoved;
}

bool JMainWindow::isLocked()
{
    return locked;
}

void JMainWindow::setLockMoved(bool flag)
{
    lockmoved = flag;
}

void JMainWindow::setLocked(bool flag)
{
    locked = flag;
}

JTitleBar* JMainWindow::getTitleBar()
{
    return titleBar;
}

QStatusBar* JMainWindow::getStatusBar()
{
    return pstatusbar;
}

QSystemTrayIcon* JMainWindow::getQSystemTrayIcon()
{
    return trayicon;
}

JFlyWidget* JMainWindow::getFlyWidget()
{
    return flyWidget;
}

void JMainWindow::swithMaxNormal()
{
    if(isMaximized())
    {
        showNormal();
    }else{
        showMaximized();
    }
}


void JMainWindow::showFlyWidget()
{
    flyWidget->show();
}

void JMainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            leftbuttonpressed = false;
        }
        else
        {
            dragPosition = e->globalPos() - frameGeometry().topLeft();
            leftbuttonpressed = true;
        }
    }
    e->accept();
}

void JMainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->y() < titleBar->height() && e->x() < titleBar->width() - 120)
    {
        swithMaxNormal();
        e->accept();
    }else{
        e->ignore();
    }
}

void JMainWindow::SetCursorStyle(enum_Direction direction)
{
    //设置上下左右以及右上、右下、左上、坐下的鼠标形状
    switch(direction)
    {
    case eTop:
    case eBottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case eRight:
    case eLeft:
        setCursor(Qt::SizeHorCursor);
        break;
    case eNormal:
        setCursor(Qt::ArrowCursor);
    default:
        setCursor(Qt::ArrowCursor);
        break;
    }
}

void JMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    leftbuttonpressed = false;
    titleBar->clearChecked();
    e->accept();
}

void JMainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isMaximized())
    {
        e->ignore();
    }
    else
    {

        if(e->y() < titleBar->height() && e->x() > titleBar->width() - 120)
        {
            e->ignore();
        }
        else{
            if(leftbuttonpressed)
            {
                if(getTitleBar()->getFixedflag())
                {
                    move(e->globalPos() - dragPosition);
                }
                e->accept();
            }

        }
    }

}

void JMainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
    else if (e->key() == Qt::Key_F11) {
        titleBar->getMaxButton()->click();
    }
}

void JMainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    QMainWindow::closeEvent(event);
}


void JMainWindow::animationClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(1500);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start();
}

void JMainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
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
                setLocked(locked);
            }
            else
            {
                if(! locked)
                {
                    hide();
                }
            }
            break;
        case QSystemTrayIcon::Context:
            break;
        default:
            break;
        }
}

JMainWindow::~JMainWindow()
{
    printf("111111\n");
}

}   //namespace JNQTF
