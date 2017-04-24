/****************************************************************************
**
** Copyright (C) 2017 JIMSDOG
**
** JNQTFramework is a frameworke based on Qt5.3, you will be more efficient with it.
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

#ifndef __JTitleBar_H__
#define __JTitleBar_H__

#include "JToolButton.h"
#include <QFrame>
#include <QLabel>


namespace JNQTF
{

#define Title_Height 25

class JTitleBar : public QFrame
{
    Q_OBJECT
private:
    QIcon* logoIcon;
    QIcon* settingsIcon;
    QIcon* skinIcon;
    QIcon* minIcon;
    QIcon* maxIcon;
    QIcon* normalIcon;
    QIcon* closeIcon;
    QLabel* titleLabel;
    JToolButton* logoButton;
    JToolButton* settingButton;
    JToolButton* skinButton;
    JToolButton* fixButton;
    JToolButton* minButton;
    JToolButton* maxButton;
    JToolButton* closeButton;
    bool normal_max_flag;
    bool fixflag;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    QString title;
    static JTitleBar* instance;

public:
    explicit JTitleBar(QWidget *parent = 0);
    static JTitleBar* getInstace();

    bool getFixedflag();

    void setTitleBarHeight(int height);
    void setSettingMenu(QMenu* menu);

    void setLogoButton(const char * str, const char *objectName=NULL);
    JToolButton* getLogoButton();
    void setLogoButtonVisible(bool visible);
    bool isLogoButtonVisible();

    void setTitleLabel(QString str , const char *objectName=NULL);
    QLabel* getTitleLabel();
    void setTitleLabelVisible(bool visible);
    bool isTitleLabelVisible();

    void setSettingButton(const char * str, const char *objectName=NULL);
    JToolButton* getSettingButton();
    void setSettingButtonVisible(bool visible);
    bool isSettingButtonVisible();

    void setSkinButton(const char * str, const char *objectName=NULL);
    JToolButton* getSkinButton();
    void setSkinButtonVisible(bool visible);
    bool isSkinButtonVisible();

    void setFixButton(const char * str, const char *objectName=NULL);
    JToolButton* getFixButton();
    void setFixButtonVisible(bool visible);
    bool isFixButtonVisible();

    void setMinButton(const char * str, const char *objectName=NULL);
    JToolButton* getMinButton();
    void setMinButtonVisible(bool visible);
    bool isMinButtonVisible();

    void setMaxButton(const char * str, const char *objectName=NULL);
    JToolButton* getMaxButton();
    void setMaxButtonVisible(bool visible);
    bool isMaxButtonVisible();

    void setCloseButton(const char * str, const char *objectName=NULL);
    JToolButton* getCloseButton();
    void setCloseButtonVisible(bool visible);
    bool isCloseButtonVisible();

signals:
    void maximumed();
    void minimuned();
    void normaled();
    void closed();

public slots:
    void switchMaxMin();
    void changeSkin();
    void clearChecked();
    void changeFix();

};

}   //namespace JNQTF

#endif // __JTitleBar_H__
