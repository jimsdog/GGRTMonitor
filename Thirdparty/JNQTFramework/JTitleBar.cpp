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

#include "JTitleBar.h"
#include <QHBoxLayout>

namespace JNQTF
{

JTitleBar* JTitleBar::instance = NULL;

JTitleBar::JTitleBar(QWidget *parent) :
    QFrame(parent)
{
    initData();
    initUI();
    initConnect();
    fixButton->click();
}

JTitleBar* JTitleBar::getInstace()
{
    if(!instance)
    {
        instance = new JTitleBar();
    }
    return instance;
}

void JTitleBar::initData()
{
    title = tr("");
    logoButton = new JToolButton();
    logoButton->setObjectName(QString("titleToolButton"));
    titleLabel = new QLabel;
    settingButton = new JToolButton();
    settingButton->setFocusPolicy(Qt::NoFocus);
    settingButton->setObjectName(QString("titleToolButton"));
    skinButton = new JToolButton();
    skinButton->setObjectName(QString("titleToolButton"));
    fixButton = new JToolButton();
    fixButton->setObjectName(QString("titleToolButton"));
    fixButton->setFocusPolicy(Qt::NoFocus);
    minButton = new JToolButton();
    minButton->setObjectName(QString("titleToolButton"));
    maxButton = new JToolButton();
    maxButton->setObjectName(QString("titleToolButton"));
    closeButton = new JToolButton();
    closeButton->setObjectName(QString("titleToolButton"));

    logoButton->setFocusPolicy(Qt::NoFocus);
    settingButton->setFocusPolicy(Qt::NoFocus);
    skinButton->setFocusPolicy(Qt::NoFocus);
    fixButton->setFocusPolicy(Qt::NoFocus);
    minButton->setFocusPolicy(Qt::NoFocus);
    maxButton->setFocusPolicy(Qt::NoFocus);
    closeButton->setFocusPolicy(Qt::NoFocus);

    normal_max_flag = true;
    fixflag = false;
    maxIcon =  new QIcon(QString(":/skin/icons/dark/appbar.fullscreen.box.png"));
    normalIcon =  new QIcon(QString(":/skin/icons/dark/appbar.app.png"));
}

void JTitleBar::initUI()
{
    setTitleBarHeight(Title_Height);
    setObjectName(QString("FTitleBar"));
    setLogoButton(":/images/skin/images/QFramer.png");
    setTitleLabel(tr("QFramer"), "FTitleLabel");
    setSettingButton(":/skin/icons/dark/appbar.control.down.png");
    setSkinButton(":/skin/icons/dark/appbar.clothes.shirt.png");
    setFixButton(":/skin/icons/dark/appbar.lock.png");
    setMinButton(":/skin/icons/dark/appbar.minus.png");
    setMaxButton(":/skin/icons/dark/appbar.app.png");
    setCloseButton(":/skin/icons/dark/appbar.close.png", "close");

    QHBoxLayout* mainlayout = new QHBoxLayout;
    mainlayout->addWidget(logoButton);
    mainlayout->addWidget(titleLabel);
    mainlayout->addStretch();
    mainlayout->addWidget(settingButton);
    mainlayout->addWidget(skinButton);
    mainlayout->addWidget(fixButton);
    mainlayout->addWidget(minButton);
    mainlayout->addWidget(maxButton);
    mainlayout->addWidget(closeButton);
    mainlayout->setContentsMargins(0, 0, 5, 0);
    mainlayout->setSpacing(0);
    setLayout(mainlayout);
}

void JTitleBar::initConnect()
{
    connect(settingButton, SIGNAL(clicked()), settingButton, SLOT(showMenu()));
    connect(skinButton, SIGNAL(clicked()), skinButton, SLOT(showMenu()));
    connect(fixButton, SIGNAL(clicked()), this, SLOT(changeFix()));
    connect(maxButton, SIGNAL(clicked()), this, SIGNAL(maximumed()));
    connect(minButton, SIGNAL(clicked()), this, SIGNAL(minimuned()));
    connect(closeButton, SIGNAL(clicked()), this, SIGNAL(closed()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(switchMaxMin()));
}

void JTitleBar::changeFix()
{
    if(fixflag)
    {
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.lock.png"));
    }
    else{
        fixButton->setIcon(QIcon(":/skin/icons/dark/appbar.unlock.keyhole.png"));
    }
    fixflag = ! fixflag;
}


bool JTitleBar::getFixedflag()
{
    return fixflag;
}

void JTitleBar::clearChecked()
{
    settingButton->setChecked(false);
    skinButton->setChecked(false);
    fixButton->setChecked(false);
    minButton->setChecked(false);
    maxButton->setChecked(false);
    closeButton->setChecked(false);
}

void JTitleBar::setSettingMenu(QMenu *menu)
{
    settingButton->setMenu(menu);
}

void JTitleBar::switchMaxMin()
{
    if(normal_max_flag)
    {
        maxButton->setIcon(*maxIcon);
        normal_max_flag = false;
    }
    else{
        maxButton->setIcon(*normalIcon);
        normal_max_flag = true;
    }
}

void JTitleBar::changeSkin()
{
//    BgSkinPopup* skinPopup = new BgSkinPopup;
//    skinPopup->move(QWidget::mapToGlobal(skinButton->geometry().bottomLeft()));
//    skinPopup->show();
}

void JTitleBar::setTitleBarHeight(int height)
{
    setFixedHeight(height);
    logoButton->setIconSize(QSize(height, height));
    titleLabel->setFixedHeight(height);
    settingButton->setIconSize(QSize(height, height));
    skinButton->setIconSize(QSize(height, height));
    minButton->setIconSize(QSize(height, height));
    maxButton->setIconSize(QSize(height, height));
    closeButton->setIconSize(QSize(height, height));
}

void JTitleBar::setLogoButton(const char *str, const char *objectName)
{

    logoButton->setIcon(QIcon(QString(str)));
    logoButton->setIconSize(QSize(height(), height()));
    if(objectName)
        logoButton->setObjectName(QString(objectName));
}

JToolButton* JTitleBar::getLogoButton()
{
    return logoButton;
}


void JTitleBar::setLogoButtonVisible(bool visible)
{
    logoButton->setVisible(visible);
}

bool JTitleBar::isLogoButtonVisible()
{
    return logoButton->isVisible();
}


void JTitleBar::setTitleLabel(QString str, const char *objectName)
{
    titleLabel->setText(str);
    titleLabel->setFixedHeight(height());
    if (objectName)
    {
        titleLabel->setObjectName(QString(objectName));
    }
}

QLabel* JTitleBar::getTitleLabel()
{
    return titleLabel;
}

void JTitleBar::setTitleLabelVisible(bool visible)
{
    titleLabel->setVisible(visible);
}

bool JTitleBar::isTitleLabelVisible()
{
    return titleLabel->isVisible();
}

void JTitleBar::setSettingButton(const char *str, const char *objectName)
{

    settingButton->setIcon(QIcon(QString(str)));
    settingButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        settingButton->setObjectName(QString(objectName));
    }
}


JToolButton* JTitleBar::getSettingButton()
{
    return settingButton;
}


void JTitleBar::setSettingButtonVisible(bool visible)
{
    settingButton->setVisible(visible);
}

bool JTitleBar::isSettingButtonVisible()
{
    return settingButton->isVisible();
}


void JTitleBar::setSkinButton(const char *str, const char *objectName)
{

    skinButton->setIcon(QIcon(QString(str)));
    skinButton->setIconSize(QSize(height(), height()));
    if(objectName)
    {
        skinButton->setObjectName(QString(objectName));
    }
}

JToolButton* JTitleBar::getSkinButton()
{
    return skinButton;
}


void JTitleBar::setSkinButtonVisible(bool visible)
{
    skinButton->setVisible(visible);
}

bool JTitleBar::isSkinButtonVisible()
{
    return skinButton->isVisible();
}


void JTitleBar::setFixButton(const char *str, const char *objectName)
{

    fixButton->setIcon(QIcon(QString(str)));
    fixButton->setIconSize(QSize(height(), height()));
    if(objectName)
    {
        fixButton->setObjectName(QString(objectName));
    }
}

JToolButton* JTitleBar::getFixButton()
{
    return fixButton;
}


void JTitleBar::setFixButtonVisible(bool visible)
{
    fixButton->setVisible(visible);
}

bool JTitleBar::isFixButtonVisible()
{
    return fixButton->isVisible();
}

void JTitleBar::setMinButton(const char *str, const char *objectName)
{
    minButton->setIcon(QIcon(QString(str)));
    minButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        minButton->setObjectName(QString(objectName));

    }
}

JToolButton* JTitleBar::getMinButton()
{
    return minButton;
}


void JTitleBar::setMinButtonVisible(bool visible)
{
    minButton->setVisible(visible);
}

bool JTitleBar::isMinButtonVisible()
{
    return minButton->isVisible();
}


void JTitleBar::setMaxButton(const char *str, const char *objectName)
{

    maxButton->setIcon(QIcon(QString(str)));
    maxButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {
        maxButton->setObjectName(QString(objectName));

    }
}


JToolButton* JTitleBar::getMaxButton()
{
    return maxButton;
}


void JTitleBar::setMaxButtonVisible(bool visible)
{
    maxButton->setVisible(visible);
}

bool JTitleBar::isMaxButtonVisible()
{
    return maxButton->isVisible();
}


void JTitleBar::setCloseButton(const char *str, const char *objectName)
{
    closeButton->setIcon(QIcon(QString(str)));
    closeButton->setIconSize(QSize(height(), height()));
    if (objectName)
    {

        closeButton->setObjectName(QString(objectName));

    }
}

JToolButton* JTitleBar::getCloseButton()
{
    return closeButton;
}


void JTitleBar::setCloseButtonVisible(bool visible)
{
    closeButton->setVisible(visible);
}

bool JTitleBar::isCloseButtonVisible()
{
    return closeButton->isVisible();
}

}   //namespace JNQTF

