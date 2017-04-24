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

#include "JFlyWidget.h"
#include<QBitmap>
#include<QApplication>
#include<QMainWindow>
#include<QCursor>


namespace JNQTF
{

JFlyWidget::JFlyWidget(QWidget *parent) :
    QWidget(parent)
{
    p = parent;
    settingmenu = NULL;
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
    initData();
    initUI();
    initConnect();
}

void JFlyWidget::initData()
{
    m_Pixmap.load(QString(":/images/skin/images/QFramer.png"));
}

void JFlyWidget::initUI()
{
    resize(m_Pixmap.size());
    setMask(m_Pixmap.mask());
}

void JFlyWidget::initConnect()
{

}

void JFlyWidget::setMenu(QMenu *menu)
{
    settingmenu = menu;
}

void JFlyWidget::mousePressEvent(QMouseEvent *event)
{
    //按住左键可以托动窗口，按下右键关闭程序
    if(event->button() == Qt::LeftButton)
    {
        m_CurrentPos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
    {
        settingmenu->exec(QCursor::pos());
    }
}

void JFlyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    p->setVisible(! p->isVisible());
}

void JFlyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        move(event->globalPos() - m_CurrentPos);
        event->accept();
    }
}

void JFlyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_Pixmap);
}

void JFlyWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    //鼠标离开窗口时是普通的指针
    setCursor(Qt::ArrowCursor);
}

void JFlyWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    //鼠标留在窗口上时是一个手指
    setCursor(Qt::PointingHandCursor);
}

}   //namespace JNQTF
