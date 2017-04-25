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

#ifndef __JMainWindow_H__
#define __JMainWindow_H__

#include <QMainWindow>
#include <QStatusBar>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "JFlyWidget.h"
#include "JTitleBar.h"
#include "JCenterWindow.h"

namespace JNQTF
{


enum enum_Direction{
    eLeft,
    eTop,
    eRight,
    eBottom,
    eNormal
};

class JMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPoint dragPosition;
    bool leftbuttonpressed;
    bool lockmoved;
    bool locked;

    void readSettings();
    void writeSettings();

    JTitleBar * titleBar;
    QStatusBar *pstatusbar;
    QSystemTrayIcon *trayicon;
    JFlyWidget* flyWidget;

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent * event);
    void SetCursorStyle(enum_Direction i);

public:
    JMainWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    JTitleBar* getTitleBar();
    QStatusBar* getStatusBar();
    QSystemTrayIcon* getQSystemTrayIcon();
    JFlyWidget* getFlyWidget();
    void animationClose();
    bool isMoved();
    bool isLocked();
    ~JMainWindow();

signals:
    void Hidden();
public slots:
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
    void setLockMoved(bool flag);
    void setLocked(bool flag);
};

}   //namespace JNQTF

#endif // __JMainWindow_H__
