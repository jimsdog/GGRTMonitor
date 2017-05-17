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

#ifndef __ECMAINWINDOW_H__
#define __ECMAINWINDOW_H__

#include <QMainWindow>
#include <QCloseEvent>
#include <QStatusBar>

#include "ECMainFrame.h"
#include "ECSpeech.h"

namespace ECFramework
{

class ECSettingMenu;

class ECMainWindow : public QMainWindow
{
    Q_OBJECT
private:
    ECMainFrame             *m_mainframe;
    QStatusBar              *m_pstatusbar;

    ECSettingMenu           *m_settingmenu;

    QPoint                  m_dragPosition;
    bool                    m_leftbuttonpressed;
    bool                    m_lockmoved;
    bool                    m_locked;

    ECSpeech                *m_speech;

protected:
    void resizeEvent(QResizeEvent * event);
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent * event);

private:
    void initData();
    void initConnect();
    void initUI();
public:
    explicit ECMainWindow(QWidget *parent = 0);

    QStatusBar* GetStatusBar();

signals:
    void Hidden();

public slots:
    void refreshAction();
    void swithMaxNormal();
    void showFlyWidget();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
    void showMainWindow();

    void settingmenuShowAbout();

};

}   //namespace ECFramework

#endif // __ECMAINWINDOW_H__
