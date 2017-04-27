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

#ifndef __ECNavigationBar_H__
#define __ECNavigationBar_H__


#include <QFrame>
#include <QHBoxLayout>
#include "ECNavigationButton.h"



namespace ECFramework
{

class ECNavigationBar : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout*        m_navlayout;
    int                 m_cIndex;

    QList<ECNavigationButton*>      m_buttons;
    QList<QString>                  m_buttonTitles;

public:
    static ECNavigationBar* m_instance;

private:
    void initData();
    void initConnect();
    void initUI();
    void resetLayout();

public:
    explicit ECNavigationBar(QWidget *parent = 0);
    static ECNavigationBar* getInstace(QWidget *parent = 0);

    int GetCurrentIndex();
    int GetCount();
    void SetCurrentIndex(int index);

    void AddNavgationButton(QString imgpath, QString title);

signals:
    void IndexChanged(int i);
private slots:
    void SetButtonChecked();
};

}   //namespace ECFramework

#endif // __ECNavigationBar_H__
