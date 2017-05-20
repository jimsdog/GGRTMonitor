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

#include <QApplication>
#include "ECMoveableContainer.h"

namespace ECFramework
{

ECMoveableContainer::ECMoveableContainer(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);

    m_webengineview = new QWebEngineView(this);
    QUrl url = QUrl::fromUserInput("https://www.baidu.com/");
    m_webengineview->setUrl(url);

    m_maskwidget = new QWidget(this);
    m_maskwidget->setStyleSheet("background-color: rgba(0, 255, 0, 120);");
    //m_maskwidget->setAttribute(Qt::WA_TranslucentBackground);
    //m_maskwidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    m_maskwidget->installEventFilter(this);

    qDebug()<<"ECMoveableContainer ------------";
}

bool ECMoveableContainer::eventFilter(QObject *obj, QEvent *event)
{
    //return QObject::eventFilter(obj, event);

    //return QWidget::eventFilter(obj, event);

    bool ret = false;
    if(obj == m_maskwidget && event->type() == QEvent::MouseButtonPress)
    {
        m_maskwidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    }
    ret = QWidget::eventFilter(obj, event);
    if(obj == m_maskwidget && event->type() == QEvent::MouseButtonPress)
    {
        m_maskwidget->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    }

    return ret;
}

bool ECMoveableContainer::event(QEvent *event)
{
    return QWidget::event(event);
    /*bool ret = false;
    if(event->type() == QEvent::MouseButtonPress)
    {
        m_maskwidget->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    }
    ret = QWidget::event(event);
    if(event->type() == QEvent::MouseButtonPress)
    {
        m_maskwidget->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    }

    return ret;*/
}

void ECMoveableContainer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    m_webengineview->resize(size());
    m_maskwidget->resize(size());
}

void ECMoveableContainer::mouseReleaseEvent(QMouseEvent *e)
{
    m_leftbuttonpressed = false;
    e->accept();
}

void ECMoveableContainer::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        if(1)
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


void ECMoveableContainer::mouseMoveEvent(QMouseEvent *e)
{
    if(1)
    {
        if(m_leftbuttonpressed)
        {
            move(e->globalPos() - m_dragPosition);
            e->accept();
        }
    }
    else
    {
        e->ignore();
    }
}

void ECMoveableContainer::mouseDoubleClickEvent(QMouseEvent *e)
{
    QWidget::mouseDoubleClickEvent(e);
}

void ECMoveableContainer::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape){
        close();
    }
}

}   //namespace ECFramework
