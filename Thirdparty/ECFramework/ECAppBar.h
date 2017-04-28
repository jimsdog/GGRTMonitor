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

#ifndef ECAPPBAR_H
#define ECAPPBAR_H

#include <QFrame>
#include <QVBoxLayout>
#include "ECSystemToolBar.h"


namespace ECFramework
{

class ECAppBar : public QFrame
{
    Q_OBJECT
private:
    QVBoxLayout*        m_mainlayout;
    ECSystemToolBar*    m_systemtoolbar;

private:
    void initData();
    void initConnect();
    void initUI();
public:
    static ECAppBar* m_instance;
public:
    explicit ECAppBar(QWidget *parent = 0);
    static ECAppBar* getInstace(QWidget *parent = 0);

    void SetSystemToolSettingMenu(QMenu* menu);
};

}   //namespace ECFramework

#endif // ECAPPBAR_H
