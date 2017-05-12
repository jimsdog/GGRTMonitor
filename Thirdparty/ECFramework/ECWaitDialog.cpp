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

#include <QVBoxLayout>
#include "ECWaitDialog.h"


namespace ECFramework
{

ECWaitDialog::ECWaitDialog(QWidget *parent)
    :QDialog(parent)
{
    setObjectName("ECWaitDialog");

    initData();
    initUI();
    initConnect();
}

void ECWaitDialog::initData()
{
    m_loading = new ECLoading(this);
}

void ECWaitDialog::initUI()
{
    setFixedSize(300, 400);
    setWindowOpacity(0.5);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setStyleSheet("background-color:transparent;");

    m_loading->setStyleSheet("background-color: rgb(55, 135,215);border-radius:10px;");
    m_loading->setGeometry(0, 0, 300, 400);

    /*QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->addItem(m_loading);
    mainlayout->addStretch();
    mainlayout->setContentsMargins(0, 0, 0, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);*/
}

void ECWaitDialog::initConnect()
{

}

}   //namespace ECFramework
