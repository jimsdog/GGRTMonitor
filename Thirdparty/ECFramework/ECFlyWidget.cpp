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


#include <QImageReader>
#include <QImage>
#include <QBitmap>
#include "ECFlyWidget.h"

namespace ECFramework
{

ECFlyWidget::ECFlyWidget(QWidget *parent)
    : QWidget(parent)
{
    setObjectName(QString("ECFlyWidget"));

    m_parent = parent;
    m_settingmenu = NULL;
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::ToolTip);
}

void ECFlyWidget::initData()
{
    QImageReader source(m_imgpath);
    if(source.canRead())
    {
        //m_pixmap.load(m_imgpath);
        QImage *img = new QImage(m_imgpath);
        *img = img->scaled(img->size()*0.7, Qt::KeepAspectRatio);
        m_pixmap = QPixmap::fromImage(*img);
    }
}

void ECFlyWidget::initUI()
{
    QString qssstr = QLatin1String("QWidget#ECFlyWidget{\
                                   background-color: transparent;\
                               }");
    setStyleSheet(qssstr);

    QImageReader source(m_imgpath);
    if(source.canRead())
    {
        resize(m_pixmap.size());
        setMask(m_pixmap.mask());
    }
}

void ECFlyWidget::initConnect()
{

}

void ECFlyWidget::Init(QString imgpath, QMenu* menu)
{
    m_imgpath = imgpath;
    m_settingmenu = menu;

    initData();
    initUI();
    initConnect();
}

void ECFlyWidget::mousePressEvent(QMouseEvent *event)
{
    //按住左键可以托动窗口，按下右键关闭程序
    if(event->button() == Qt::LeftButton)
    {
        m_currentpos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    else if(event->button() == Qt::RightButton)
    {
        if(m_settingmenu)
        {
            m_settingmenu->exec(QCursor::pos());
        }
    }
}

void ECFlyWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    emit showmainwindow();

    /*if(m_parent)
    {
        m_parent->setVisible(! m_parent->isVisible());
    }*/
}

void ECFlyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton)
    {
        move(event->globalPos() - m_currentpos);
        event->accept();
    }
}

void ECFlyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_pixmap);
}

void ECFlyWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void ECFlyWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::PointingHandCursor);
}

}   //namespace ECFramework
