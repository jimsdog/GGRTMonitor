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

#include "JBaseDialog.h"
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>

namespace JNQTF
{

JBaseDialog::JBaseDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    initData();
    initUI();
    initConnect();
}

void JBaseDialog::initData()
{

}

void JBaseDialog::initUI()
{
    resize(0, 0);
    titlebar = new JTitleBar;
    titlebar->setSettingButtonVisible(false);
    titlebar->setSkinButtonVisible(false);
    titlebar->setFixButtonVisible(false);
    titlebar->setMinButtonVisible(false);
    titlebar->setMaxButtonVisible(false);

    QVBoxLayout* mainLayout = new QVBoxLayout;

    mainLayout->addWidget(titlebar);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void JBaseDialog::initConnect()
{
    connect(titlebar->getCloseButton(), SIGNAL(clicked()), this, SLOT(animationClose()));
}

JTitleBar* JBaseDialog::getTitleBar()
{
    return titlebar;
}

void JBaseDialog::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
    }
    e->accept();
}

void JBaseDialog::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void JBaseDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(e->y() < height() - 30){
        move(e->globalPos() - dragPosition);
        e->accept();
    }
    else{
        e->ignore();
    }

}

void JBaseDialog::showEvent(QShowEvent *event)
{

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(200);
    int w = desktopWidget->availableGeometry().width();
    int h = desktopWidget->availableGeometry().height();
    animation->setStartValue(QRect(w * 0.5, h*0.5, 0, 0));
    animation->setEndValue(QRect(w /2 - normalSize.width()/2,
                                 h / 2 - normalSize.height() / 2,
                                 normalSize.width(), normalSize.height()));
    animation->start();
    QWidget::showEvent(event);
}

void JBaseDialog::closeEvent(QCloseEvent *event)
{

    QWidget::closeEvent(event);
}


void JBaseDialog::animationClose()
{
    QRect noraml = geometry();
    QRect closeRect = QRect(noraml.x(), noraml.y() + noraml.height()/2, noraml.width(), 0);
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    connect(animation, SIGNAL(finished()), this, SLOT(close()));
    animation->setDuration(100);
    animation->setStartValue(noraml);
    animation->setEndValue(closeRect);
    animation->start();
}

}   //namespace JNQTF
