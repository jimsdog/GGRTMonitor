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

#include "JCenterWindow.h"
#include "JTitleBar.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEasingCurve>
#include <QLabel>
#include <QTime>

namespace JNQTF
{

JCenterWindow::JCenterWindow(QWidget *parent)
    :QFrame(parent)
{
    qDebug("JCenterWindow init");
    initData();
    initUI();
    initConnect();
}

void JCenterWindow::initData()
{
    preindex = 0;
}

void JCenterWindow::initUI()
{
    setObjectName(QString("JCenterWindow"));
    navagationBar = new JNavgationBar();
    stackWidget = new QStackedWidget();

    navlayout = new QBoxLayout(QBoxLayout::TopToBottom);
    navlayout->addWidget(navagationBar);
    navlayout->addWidget(stackWidget);
    navlayout->setContentsMargins(0, 0 ,0 ,0);
    navlayout->setSpacing(0);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(JTitleBar::getInstace());
    mainLayout->addLayout(navlayout);
    mainLayout->setContentsMargins(0, 0 ,0 ,0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void JCenterWindow::swicthLayout(QBoxLayout::Direction direction)
{
    navlayout->setDirection(direction);
}


void JCenterWindow::setAlignment(Alignment_Direction direction)
{
    switch (direction) {
    case TopLeft:
        navagationBar->setObjectName(QString("JNavgationBar_bottom"));
        navagationBar->setAlignment_topLeft();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case TopCenter:
        navagationBar->setObjectName(QString("JNavgationBar_bottom"));
        navagationBar->setAlignment_topCenter();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();

        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case TopRight:
        navagationBar->setObjectName(QString("JNavgationBar_bottom"));
        navagationBar->setAlignment_topRight();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::TopToBottom);
        break;
    case RightTop:
        navagationBar->setObjectName(QString("JNavgationBar_left"));
        navagationBar->setAlignment_rightTop();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case RightCenter:
        navagationBar->setObjectName(QString("JNavgationBar_left"));
        navagationBar->setAlignment_rightCenter();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case RightBottom:
        navagationBar->setObjectName(QString("JNavgationBar_left"));
        navagationBar->setAlignment_rightBottom();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::RightToLeft);
        break;
    case BottomRight:
        navagationBar->setObjectName(QString("JNavgationBar_top"));
        navagationBar->setAlignment_bottomRight();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case BottomCenter:
        navagationBar->setObjectName(QString("JNavgationBar_top"));
        navagationBar->setAlignment_bottomCenter();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case BottomLeft:
        navagationBar->setObjectName(QString("JNavgationBar_top"));
        navagationBar->setAlignment_bottomLeft();
        navagationBar->resize(QSize(stackWidget->width(), navagationBar->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::BottomToTop);
        break;
    case LeftBottom:
        navagationBar->setObjectName(QString("JNavgationBar_right"));
        navagationBar->setAlignment_leftBottom();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    case LeftCenter:
        navagationBar->setObjectName(QString("JNavgationBar_right"));
        navagationBar->setAlignment_leftCenter();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    case LeftTop:
        navagationBar->setObjectName(QString("JNavgationBar_right"));
        navagationBar->setAlignment_leftTop();
        navagationBar->resize(QSize(navagationBar->width(), stackWidget->height()));
        navagationBar->adjustSize();
        swicthLayout(QBoxLayout::LeftToRight);
        break;
    default:
        break;
    }
}


void JCenterWindow::initConnect()
{
    connect(navagationBar, SIGNAL(indexChanged(int)), this, SLOT(switchscreen(int)));
}


void JCenterWindow::addWidget(const QString &tile, const QString &obejctName, QWidget *widget)
{
    navagationBar->addNavgationTile(tile, obejctName);
    widget->setObjectName(obejctName);
    stackWidget->addWidget(widget);
}

JNavgationBar* JCenterWindow::getNavgationBar(){
    return navagationBar;
}

void JCenterWindow::switchscreen(const int index)
{
    int n = 0;
    if (index == stackWidget->currentIndex())
    {
        return;
    }
    else if(index > stackWidget->currentIndex())
    {
        n = 2;
    }
    else if (index < stackWidget->currentIndex())
    {
        n = 6;
    }

    stackWidget->setCurrentIndex(index);

//    QTime time;
//    time= QTime::currentTime();
//    qsrand(time.msec()+time.second()*1000);
//    int n = qrand()%9;
//    n = 0;
    switch (n) {
    case 0:
        cloudAntimation(animationTop);
        break;
    case 1:
        cloudAntimation(animationTopRight);
        break;
    case 2:
        cloudAntimation(animationRight);
        break;
    case 3:
        cloudAntimation(animationBottomRight);
        break;
    case 4:
        cloudAntimation(animationBottom);
        break;
    case 5:
        cloudAntimation(animationBottomLeft);
        break;
    case 6:
        cloudAntimation(animationLeft);
        break;
    case 7:
        cloudAntimation(animationTopLeft);
        break;
    case 8:
        cloudAntimation(animationCenter);
        break;
    default:
        break;
    }
    preindex = index;

}


void JCenterWindow::switchscreen()
{
    stackWidget->setCurrentIndex(currentIndex);
}

void JCenterWindow::cloudAntimation(animation_Direction direction)
{
    QLabel* circle = new QLabel(stackWidget->currentWidget());
    QLabel* line = new QLabel(this);
    line->setObjectName(QString("AntimationLine"));
    line->resize(0, 2);
    line->show();
    #if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
        circle->setPixmap(QPixmap::grabWidget(stackWidget->widget(preindex), stackWidget->widget(preindex)->geometry()));
    #else
        circle->setPixmap(stackWidget->widget(preindex)->grab());
    #endif

//    circle->setScaledContents(true);
    circle->show();
    circle->resize(stackWidget->currentWidget()->size());
    QPropertyAnimation *animation = new QPropertyAnimation(circle, "geometry");

    animation->setDuration(1000);
    animation->setStartValue(circle->geometry());

    QPropertyAnimation* animation_line = new QPropertyAnimation(line, "size");
    animation_line->setDuration(1000);
    animation_line->setEasingCurve(QEasingCurve::OutCubic);

    switch (direction) {
    case animationTop:
        animation->setEndValue(QRect(circle->x(), circle->y() - 10, circle->width(), 0));
        break;
    case animationTopRight:
        animation->setEndValue(QRect(circle->width(), 0, 0, 0));
        break;
    case animationRight:
        line->move(0, stackWidget->y() - 2);
        animation->setEndValue(QRect(circle->width() + 3, 0, 0, circle->height()));
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(stackWidget->width(), 2));
        break;
    case animationBottomRight:
        animation->setEndValue(QRect(circle->width(), circle->height(), 0, 0));
        break;
    case animationBottom:
        animation->setEndValue(QRect(0, circle->height() + 10, circle->width(), 0));
        break;
    case animationBottomLeft:
        animation->setEndValue(QRect(0, circle->height(), 0, 0));
        break;
    case animationLeft:
        animation->setEndValue(QRect(-3, 0, 0, circle->height()));
        line->move(stackWidget->x(), stackWidget->y() - 2);
        animation_line->setStartValue(QSize(0, 2));
        animation_line->setEndValue(QSize(stackWidget->width(), 2));
        break;
    case animationTopLeft:
        animation->setEndValue(QRect(0, 0, 0, 0));
        break;
    case animationCenter:
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

}   //namespace JNQTF
