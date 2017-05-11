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

#ifndef __ECSETTINGMENU_H__
#define __ECSETTINGMENU_H__

#include <QMenu>
#include <QAction>

namespace ECFramework
{

class ECMainWindow;

class ECSettingMenu : public QMenu
{
    Q_OBJECT
private:
    ECMainWindow                *m_mainwindow;

    QList<QAction*>             m_actions;
    QList<QString>              m_actionNames;
    QList<QString>              m_actionIcons;
    QMap<QString, QAction*>     m_actionMaps;
private:
    void initData();
    void initUI();
    void initConnect();
public:
    explicit ECSettingMenu(QWidget *parent = 0);

public:
    void Init(ECMainWindow *mainwindow);
};

}   //namespace ECFramework

#endif // __ECSETTINGMENU_H__
