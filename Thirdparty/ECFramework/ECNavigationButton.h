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


#ifndef __ECNavigationButton_H__
#define __ECNavigationButton_H__

#include <QPushButton>


namespace ECFramework
{

class ECNavigationButton : public QPushButton
{
    Q_OBJECT
private:
    QString             m_title;
    QString             m_imgpath;
public:
    explicit ECNavigationButton(QWidget *parent = 0);

    void Init(QString imgpath, QString title);

private:
    void initData();
    void initConnect();
    void initUI();

};

}   //namespace ECFramework

#endif // __ECNavigationButton_H__
