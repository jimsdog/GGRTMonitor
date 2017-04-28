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

#ifndef __ECSYSTEMTOOLBAR_H__
#define __ECSYSTEMTOOLBAR_H__

#include <QFrame>
#include "ECToolButton.h"

namespace ECFramework
{

class ECSystemToolBar : public QFrame
{
    Q_OBJECT
private:
    ECToolButton*       m_settingButton;
    ECToolButton*       m_fixButton;
    ECToolButton*       m_minButton;
    ECToolButton*       m_maxButton;
    ECToolButton*       m_closeButton;
    bool                m_normal_max_flag;
    bool                m_fixflag;
    QString             m_fixbtn_fimgpath;
    QString             m_fixbtn_ufimgpath;
    QString             m_maxbtn_nimgpath;
    QString             m_maxbtn_mimgpath;

public:
    static ECSystemToolBar* m_instance;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    explicit ECSystemToolBar(QWidget *parent = 0);
    static ECSystemToolBar* getInstace(QWidget *parent = 0);

    bool GetFixedflag();

    void SetBarHeight(int height);
    void SetSettingMenu(QMenu* menu);

    void SetSettingButton(QString imgpath);
    ECToolButton* GetSettingButton();
    void SetSettingButtonVisible(bool visible);
    bool IsSettingButtonVisible();

    void SetFixButton(QString fimgpath, QString ufimgpath);
    ECToolButton* GetFixButton();
    void SetFixButtonVisible(bool visible);
    bool IsFixButtonVisible();

    void SetMinButton(QString imgpath);
    ECToolButton* GetMinButton();
    void SetMinButtonVisible(bool visible);
    bool IsMinButtonVisible();

    void SetMaxButton(QString nimgpath, QString mimgpath);
    ECToolButton* GetMaxButton();
    void SetMaxButtonVisible(bool visible);
    bool IsMaxButtonVisible();

    void SetCloseButton(QString imgpath);
    ECToolButton* GetCloseButton();
    void SetCloseButtonVisible(bool visible);
    bool IsCloseButtonVisible();

signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();

public slots:
    void switchMaxMin();
    void clearChecked();
    void changeFix();

};

}   //namespace ECFramework

#endif // __ECSYSTEMTOOLBAR_H__
