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

#include "JNavgationBar.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

namespace JNQTF
{

JNavgationBar::JNavgationBar(QWidget *parent)
    :QFrame(parent)
{
    initData();
    initUI();
    initConnect();
}

void JNavgationBar::initData()
{
    cIndex = 0;
}

void JNavgationBar::initUI()
{
    setObjectName(QString("JNavgationBar"));
}

void JNavgationBar::initConnect()
{
    for(int i=0; i<buttons.length(); i++)
    {
        connect(buttons.at(i), SIGNAL(clicked()), this, SLOT(setButtonChecked()));
    }
}

void JNavgationBar::addNavgationTile(const QString &tile, const QString &objectName)
{
    buttonTitles  << tile;
    JCheckAbleButton* button = new JCheckAbleButton(tile);
    buttons.append(button);
    button->setObjectName(objectName);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
}

void JNavgationBar::setAlignment_topLeft()
{
    mainlayout_topLeft = new QHBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topLeft->addWidget(buttons.at(i));
    }
    mainlayout_topLeft->addStretch();
    mainlayout_topLeft->setContentsMargins(5, 5, 5, 5);
    mainlayout_topLeft->setSpacing(0);
    setLayout(mainlayout_topLeft);
}

void JNavgationBar::setAlignment_topCenter()
{
    mainlayout_topCenter = new QHBoxLayout;
    mainlayout_topCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topCenter->addWidget(buttons.at(i));
    }
    mainlayout_topCenter->addStretch();
    mainlayout_topCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_topCenter->setSpacing(0);
    setLayout(mainlayout_topCenter);
}

void JNavgationBar::setAlignment_topRight()
{
    mainlayout_topRight = new QHBoxLayout;
    mainlayout_topRight->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_topRight->addWidget(buttons.at(i));
    }
    mainlayout_topRight->setContentsMargins(5, 5, 5, 5);
    mainlayout_topRight->setSpacing(0);
    setLayout(mainlayout_topRight);
}


void JNavgationBar::setAlignment_bottomLeft()
{
    mainlayout_bottomLeft = new QHBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomLeft->addWidget(buttons.at(i));
    }
    mainlayout_bottomLeft->addStretch();
    mainlayout_bottomLeft->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomLeft->setSpacing(0);
    setLayout(mainlayout_bottomLeft);
}


void JNavgationBar::setAlignment_bottomCenter()
{
    mainlayout_bottomCenter = new QHBoxLayout;
    mainlayout_bottomCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomCenter->addWidget(buttons.at(i));
    }
    mainlayout_bottomCenter->addStretch();
    mainlayout_bottomCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomCenter->setSpacing(0);
    setLayout(mainlayout_bottomCenter);

}

void JNavgationBar::setAlignment_bottomRight()
{
    mainlayout_bottomRight = new QHBoxLayout;
    mainlayout_bottomRight->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_bottomRight->addWidget(buttons.at(i));
    }
    mainlayout_bottomRight->setContentsMargins(5, 5, 5, 5);
    mainlayout_bottomRight->setSpacing(0);
    setLayout(mainlayout_bottomRight);
}

void JNavgationBar::setAlignment_leftTop()
{
    mainlayout_leftTop = new QVBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftTop->addWidget(buttons.at(i));
    }
    mainlayout_leftTop->addStretch();
    mainlayout_leftTop->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftTop->setSpacing(0);
    setLayout(mainlayout_leftTop);
}

void JNavgationBar::setAlignment_leftCenter()
{
    mainlayout_leftCenter = new QVBoxLayout;
    mainlayout_leftCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftCenter->addWidget(buttons.at(i));
    }
    mainlayout_leftCenter->addStretch();
    mainlayout_leftCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftCenter->setSpacing(0);
    setLayout(mainlayout_leftCenter);
}

void JNavgationBar::setAlignment_leftBottom()
{
    mainlayout_leftBottom = new QVBoxLayout;
    mainlayout_leftBottom->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_leftBottom->addWidget(buttons.at(i));
    }
    mainlayout_leftBottom->setContentsMargins(5, 5, 5, 5);
    mainlayout_leftBottom->setSpacing(0);
    setLayout(mainlayout_leftBottom);
}

void JNavgationBar::setAlignment_rightTop()
{
    mainlayout_rightTop = new QVBoxLayout;
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightTop->addWidget(buttons.at(i));
    }
    mainlayout_rightTop->addStretch();
    mainlayout_rightTop->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightTop->setSpacing(0);
    setLayout(mainlayout_rightTop);
}

void JNavgationBar::setAlignment_rightCenter()
{
    mainlayout_rightCenter = new QVBoxLayout;
    mainlayout_rightCenter->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightCenter->addWidget(buttons.at(i));
    }
    mainlayout_rightCenter->addStretch();
    mainlayout_rightCenter->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightCenter->setSpacing(0);
    setLayout(mainlayout_rightCenter);
}

void JNavgationBar::setAlignment_rightBottom()
{
    mainlayout_rightBottom = new QVBoxLayout;
    mainlayout_rightBottom->addStretch();
    for(int i=0; i < buttons.length(); i++)
    {
        mainlayout_rightBottom->addWidget(buttons.at(i));
    }
    mainlayout_rightBottom->setContentsMargins(5, 5, 5, 5);
    mainlayout_rightBottom->setSpacing(0);
    setLayout(mainlayout_rightBottom);
}

int JNavgationBar::currentIndex()
{
    return cIndex;
}

void JNavgationBar::setCurrentIndex(int index)
{
    buttons.at(index)->click();
}

int JNavgationBar::count()
{
    return buttons.size();
}

void JNavgationBar::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            emit indexChanged(i);
            cIndex = i;
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}

}   //namespace JNQTF

