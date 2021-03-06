﻿/****************************************************************************
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

#ifndef __ECWAITDIALOG_H__
#define __ECWAITDIALOG_H__


#include <QDialog>
#include "ECLoading.h"

namespace ECFramework
{

class ECWaitDialog : public QDialog
{
    Q_OBJECT
private:
    ECLoading           *m_loading;
private:
    void initData();
    void initConnect();
    void initUI();
public:
    explicit ECWaitDialog(QWidget *parent = 0);
};

}   //namespace ECFramework

#endif // __ECWAITDIALOG_H__
