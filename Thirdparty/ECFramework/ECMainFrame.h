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

#ifndef __ECMAINFRAME_H__
#define __ECMAINFRAME_H__

#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>

#include <QSystemTrayIcon>
#include "ECFlyWidget.h"
#include "ECLogoFrame.h"
#include "ECNavigationBar.h"
#include "ECAppBar.h"

namespace ECFramework
{

class ECMainFrame : public QFrame
{
    Q_OBJECT
public:
    enum Animation_Direction{
        AnimationTop,
        AnimationRight,
        AnimationBottom,
        AnimationLeft,
        AnimationTopLeft,
        AnimationTopRight,
        AnimationBottomRight,
        AnimationBottomLeft,
        AnimationCenter
    };
private:
    QVBoxLayout            *m_mainlayout;
    QHBoxLayout            *m_titlebarlayout;

    ECLogoFrame             *m_logoframe;
    ECNavigationBar         *m_navigationbar;
    ECAppBar                *m_appbar;

    QStackedWidget          *m_stackWidget;

    QSystemTrayIcon         *m_trayicon;
    ECFlyWidget             *m_flyWidget;

    int                     m_preindex;

public:
    static ECMainFrame* m_instance;

private:
    void initData();
    void initConnect();
    void initUI();

protected:
    void resizeEvent(QResizeEvent * event);

public:
    explicit ECMainFrame(QWidget *parent = 0);
    static ECMainFrame* getInstace(QWidget *parent = 0);


    void SetLogo(QString imgpath, QString title);
    void AddNavgation(QString imgpath, QString title, QWidget* widget);
    void ResetNavgationLayout();
    void SetAppSettingMenu(QMenu* menu);

    ECLogoFrame* GetLogoFrame();
    ECNavigationBar* GetNavgationBar();
    ECAppBar* GetAppBar();

    QSystemTrayIcon* GetQSystemTrayIcon();
    ECFlyWidget* GetFlyWidget();

    int GetTopHeight();
    int GetTopWidth();


signals:

public slots:
    void switchScreen(const int index);
    virtual void cloudAntimation(Animation_Direction direction);

};

}   //namespace ECFramework

#endif // __ECMAINFRAME_H__
