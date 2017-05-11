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

#include <QApplication>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEasingCurve>
#include <QLabel>
#include <QTime>
#include "ECMainFrame.h"



namespace ECFramework
{

ECMainFrame* ECMainFrame::m_instance = NULL;

ECMainFrame::ECMainFrame(QWidget *parent) :
    QFrame(parent)
{
    setObjectName(QString("ECMainFrame"));

    initData();
    initUI();
    initConnect();
}

ECMainFrame* ECMainFrame::getInstace(QWidget *parent)
{
    if(!m_instance)
    {
        m_instance = new ECMainFrame(parent);
    }
    return m_instance;
}

void ECMainFrame::resizeEvent(QResizeEvent *event)
{
    QFrame::resizeEvent(event);
}

int ECMainFrame::GetTopHeight()
{
    if(m_logoframe)
    {
        return m_logoframe->size().height();
    }
    else
    {
       return 0;
    }
}

int ECMainFrame::GetTopWidth()
{
    return size().width();
}

void ECMainFrame::initData()
{
    m_mainlayout = new QVBoxLayout(this);
    m_titlebarlayout = new QHBoxLayout(this);

    m_logoframe = ECLogoFrame::getInstace(this);
    m_navigationbar = ECNavigationBar::getInstace(this);
    m_appbar = ECAppBar::getInstace(this);

    m_stackWidget = new QStackedWidget(this);

    m_trayicon = new QSystemTrayIcon(QIcon(QString(":/image/ui/robot128X128.ico")), this);
    m_flyWidget = new ECFlyWidget(this);

    m_preindex = 0;
}

void ECMainFrame::initUI()
{
    QString qssstr = QLatin1String("QFrame#ECMainFrame{\
                                   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 82, 112, 255), stop:0.5 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                                   background-image: url(none);\
                                   background-repeat:repeat-xy;\
                               }");
    setStyleSheet(qssstr);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());

    resize(desktopWidget->availableGeometry().size()* 0.6);



    m_trayicon->setObjectName(QString("trayicon"));
    m_trayicon->setToolTip(QString(qApp->applicationName()));
    m_trayicon->show();

    m_flyWidget->move(desktopWidget->availableGeometry().width() * 0.6, desktopWidget->availableGeometry().height() *0.2);



    m_titlebarlayout->addWidget(m_logoframe);
    m_titlebarlayout->addWidget(m_navigationbar);
    m_titlebarlayout->addStretch();
    m_titlebarlayout->addWidget(m_appbar);
    m_titlebarlayout->setContentsMargins(0, 0, 0, 0);
    m_titlebarlayout->setSpacing(0);

    m_mainlayout->addLayout(m_titlebarlayout);
    m_mainlayout->addWidget(m_stackWidget);
    m_mainlayout->setContentsMargins(0, 0, 0, 0);
    m_mainlayout->setSpacing(0);
    setLayout(m_mainlayout);
}

void ECMainFrame::initConnect()
{
    connect(m_navigationbar, SIGNAL(indexChanged(int)), this, SLOT(switchScreen(int)));
}

void ECMainFrame::SetLogo(QString imgpath, QString title)
{
    m_logoframe->Init(imgpath, title);
}

void ECMainFrame::AddNavgation(QString imgpath, QString title, QWidget* widget)
{
    m_navigationbar->AddNavgationButton(imgpath, title);
    m_stackWidget->addWidget(widget);
}

void ECMainFrame::ResetNavgationLayout()
{
    m_navigationbar->ResetLayout();
}

void ECMainFrame::SetAppSettingMenu(QMenu* menu)
{
    m_appbar->SetSystemToolSettingMenu(menu);
}

ECLogoFrame* ECMainFrame::GetLogoFrame()
{
    return m_logoframe;
}

ECNavigationBar* ECMainFrame::GetNavgationBar()
{
    return m_navigationbar;
}

ECAppBar* ECMainFrame::GetAppBar()
{
    return m_appbar;
}

QSystemTrayIcon* ECMainFrame::GetQSystemTrayIcon()
{
    return m_trayicon;
}

ECFlyWidget* ECMainFrame::GetFlyWidget()
{
    return m_flyWidget;
}


void ECMainFrame::switchScreen(const int index)
{
    int n = 0;
    if (index == m_stackWidget->currentIndex())
    {
        return;
    }
    else if(index > m_stackWidget->currentIndex())
    {
        n = 2;
    }
    else if (index < m_stackWidget->currentIndex())
    {
        n = 6;
    }

    m_stackWidget->setCurrentIndex(index);

//    QTime time;
//    time= QTime::currentTime();
//    qsrand(time.msec()+time.second()*1000);
//    int n = qrand()%9;
//    n = 0;
    switch (n) {
    case 0:
        cloudAntimation(AnimationTop);
        break;
    case 1:
        cloudAntimation(AnimationTopRight);
        break;
    case 2:
        cloudAntimation(AnimationRight);
        break;
    case 3:
        cloudAntimation(AnimationBottomRight);
        break;
    case 4:
        cloudAntimation(AnimationBottom);
        break;
    case 5:
        cloudAntimation(AnimationBottomLeft);
        break;
    case 6:
        cloudAntimation(AnimationLeft);
        break;
    case 7:
        cloudAntimation(AnimationTopLeft);
        break;
    case 8:
        cloudAntimation(AnimationCenter);
        break;
    default:
        break;
    }
    m_preindex = index;
}

void ECMainFrame::cloudAntimation(Animation_Direction direction)
{
    QString qssstr = QLatin1String("QLabel{\
                                   background-color: rgba(0, 211, 197, 255);\
                               }");

    QLabel* circle = new QLabel(m_stackWidget->currentWidget());
    QLabel* line = new QLabel(this);
    //line->setObjectName(QString("AntimationLine"));
    line->setStyleSheet(qssstr);
    line->resize(0, 2);
    line->show();
    #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
        circle->setPixmap(QPixmap::grabWidget(m_stackWidget->widget(m_preindex), m_stackWidget->widget(m_preindex)->geometry()));
    #else
        circle->setPixmap(m_stackWidget->widget(m_preindex)->grab());
    #endif

//    circle->setScaledContents(true);
    circle->show();
    circle->resize(m_stackWidget->currentWidget()->size());
    QPropertyAnimation *animation = new QPropertyAnimation(circle, "geometry");

    animation->setDuration(1000);
    animation->setStartValue(circle->geometry());

    QPropertyAnimation* animation_line = new QPropertyAnimation(line, "size");
    animation_line->setDuration(1000);
    animation_line->setEasingCurve(QEasingCurve::OutCubic);

    switch (direction) {
    case AnimationTop:
        animation->setEndValue(QRect(circle->x(), circle->y() - 10, circle->width(), 0));
        break;
    case AnimationTopRight:
        animation->setEndValue(QRect(circle->width(), 0, 0, 0));
        break;
    case AnimationRight:
        line->move(0, m_stackWidget->y() - 2);
        animation->setEndValue(QRect(circle->width() + 3, 0, 0, circle->height()));
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(m_stackWidget->width(), 2));
        break;
    case AnimationBottomRight:
        animation->setEndValue(QRect(circle->width(), circle->height(), 0, 0));
        break;
    case AnimationBottom:
        animation->setEndValue(QRect(0, circle->height() + 10, circle->width(), 0));
        break;
    case AnimationBottomLeft:
        animation->setEndValue(QRect(0, circle->height(), 0, 0));
        break;
    case AnimationLeft:
        animation->setEndValue(QRect(-3, 0, 0, circle->height()));
        line->move(m_stackWidget->x(), m_stackWidget->y() - 2);
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(m_stackWidget->width(), 2));
        break;
    case AnimationTopLeft:
        animation->setEndValue(QRect(0, 0, 0, 0));
        break;
    case AnimationCenter:
        animation->setEndValue(QRect(circle->width()/2, circle->height()/2, 0, 0));
        break;
    default:
        break;
    }
    animation->setEasingCurve(QEasingCurve::OutCubic);

    QPropertyAnimation* animation_opacity = new QPropertyAnimation(circle, "windowOpacity");
    animation_opacity->setDuration(1000);
    animation_opacity->setStartValue(1);
    animation_opacity->setEndValue(0);
    animation_opacity->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *group = new QParallelAnimationGroup;

    connect(group,SIGNAL(finished()), circle, SLOT(hide()));
    connect(group,SIGNAL(finished()), circle, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), line, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), group, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation_opacity, SLOT(deleteLater()));
    connect(group,SIGNAL(finished()), animation_line, SLOT(deleteLater()));
    group->addAnimation(animation);
    group->addAnimation(animation_opacity);
    group->addAnimation(animation_line);
    group->start();
}



}   //namespace ECFramework
