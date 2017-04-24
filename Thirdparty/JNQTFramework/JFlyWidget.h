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

#ifndef __JFlyWidget_H__
#define __JFlyWidget_H__

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <QMenu>


namespace JNQTF
{

class JFlyWidget : public QWidget
{
    Q_OBJECT
private:
    QWidget* p;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

private:
    QPoint m_CurrentPos;
    QPixmap m_Pixmap;
public:
    QMenu* settingmenu;
public:
    explicit JFlyWidget(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void setMenu(QMenu* menu);
signals:

public slots:

};

}   //namespace JNQTF

#endif // __JFlyWidget_H__
