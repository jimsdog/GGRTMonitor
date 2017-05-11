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

#ifndef __ECFLYWIDGET_H__
#define __ECFLYWIDGET_H__

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QMenu>

namespace ECFramework
{

class ECFlyWidget : public QWidget
{
    Q_OBJECT
private:
    QWidget*            m_parent;
    QMenu*              m_settingmenu;

    QString             m_imgpath;

    QPoint              m_currentpos;
    QPixmap             m_pixmap;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

public:
    explicit ECFlyWidget(QWidget *parent = 0);

    void Init(QString imgpath, QMenu* menu);


private:
    void initData();
    void initUI();
    void initConnect();



public:
signals:
    void showmainwindow();

public slots:
};

}   //namespace ECFramework

#endif // __ECFLYWIDGET_H__
