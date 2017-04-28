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

#ifndef __ECTOOLBUTTON_H__
#define __ECTOOLBUTTON_H__

#include <QMenu>
#include <QToolButton>

namespace ECFramework
{

class ECToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ECToolButton(QWidget *parent = 0);

    void SetButtonMenu(QMenu *menu);

private:
    void initData();
    void initConnect();
    void initUI();

public slots:
    void Recover();

};

}   //namespace ECFramework

#endif // __ECTOOLBUTTON_H__
