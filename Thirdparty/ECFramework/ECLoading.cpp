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

#include <QMouseEvent>
#include "ECMainWindow.h"
#include <QApplication>

namespace ECFramework
{

ECLoading::ECLoading(QWidget *parent)
    :QWebEngineView(parent)
    ,child_(nullptr)
{
    setObjectName("ECLoading");

    setParent(parent);
    m_mainwindow = parent;
}

void ECLoading::contextMenuEvent(QContextMenuEvent *event)
{
    if(event->reason() == QContextMenuEvent::Mouse)
    {
        event->accept();
    }
}

bool ECLoading::eventFilter(QObject *obj, QEvent *ev)
{
    if (obj == child_ && (ev->type() == QEvent::MouseButtonDblClick
                          || ev->type() == QEvent::MouseButtonPress
                          || ev->type() == QEvent::MouseButtonRelease
                          || ev->type() == QEvent::MouseMove))
    {
       //qDebug()<<"eventFilter --------- QEvent::MouseButtonPress " + ev->type();
       QMouseEvent *mev = static_cast<QMouseEvent*>(ev);
       if(mev)
       {
           /*QString evtype = "";
           if(ev->type() == QEvent::MouseButtonDblClick)
               evtype = "QEvent::MouseButtonDblClick";
           else if(ev->type() == QEvent::MouseButtonPress)
               evtype = "QEvent::MouseButtonPress";
           else if(ev->type() == QEvent::MouseButtonRelease)
               evtype = "QEvent::MouseButtonRelease";
           else if(ev->type() == QEvent::MouseMove)
               evtype = "QEvent::MouseMove";
           qDebug()<<QString("eventFilter ---------  %1").arg(evtype);
           //qDebug()<<QString("eventFilter ---------  %1").arg(ev->type());*/

           //QPoint pt = child_->mapTo(m_mainwindow, mev->pos());

           QMouseEvent *pev = new QMouseEvent(mev->type(),mev->pos(),mev->button(),mev->buttons(),mev->modifiers());
           QApplication::sendEvent(parent(),pev);
       }
    }

    return QWebEngineView::eventFilter(obj, ev);
}

bool ECLoading::event(QEvent * ev)
{
    if (ev->type() == QEvent::ChildAdded) {
        QChildEvent *child_ev = static_cast<QChildEvent*>(ev);

        // there is also QObject child that should be ignored here;
        // use only QOpenGLWidget child
        QOpenGLWidget *w = qobject_cast<QOpenGLWidget*>(child_ev->child());
        if (w) {
            child_ = w;
            w->installEventFilter(this);
        }
    }

    return QWebEngineView::event(ev);
}


void ECLoading::initData()
{

}

void ECLoading::initUI()
{
    QUrl url = QUrl::fromLocalFile(m_htmlpath);
    //QUrl url = QUrl::fromUserInput(m_htmlpath);
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
