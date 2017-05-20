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

#ifndef __ECMOVEABLECONTAINER_H__
#define __ECMOVEABLECONTAINER_H__

#include <QWidget>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QWebEngineView>

namespace ECFramework
{

class ECMoveableContainer : public QWidget
{
    Q_OBJECT
private:
    QPoint                  m_dragPosition;
    bool                    m_leftbuttonpressed;

    QWidget                 *m_maskwidget;
    QWebEngineView          *m_webengineview;

protected:
    void resizeEvent(QResizeEvent * event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);

    bool eventFilter(QObject *obj, QEvent *event);

    bool event(QEvent *event);

public:
    explicit ECMoveableContainer(QWidget *parent = 0);

signals:

public slots:
};

}   //namespace ECFramework

#endif // __ECMOVEABLECONTAINER_H__
