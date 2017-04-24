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


#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QStackedLayout>
#include "JTabWidget.h"


namespace JNQTF
{


JTabWidget::JTabWidget(QWidget *parent) :
    QWidget(parent)
{
    initUI();
    initConnect();
}

void JTabWidget::initUI()
{
    tabTile = new QWidget;
    tabTile->setObjectName(QString("FTabTile"));

    stackLayout = new QStackedLayout;
    tabLayout = new QVBoxLayout;
    tabLayout->addStretch();
    tabLayout->setContentsMargins(0, 0, 0, 0);
    tabLayout->setSpacing(0);
    tabTile->setLayout(tabLayout);

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(tabTile);
    mainLayout->addLayout(stackLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

void JTabWidget::initConnect()
{


}

void JTabWidget::addWidget(const QString &tile, const QString &objectName, QWidget *widget)
{
    Q_UNUSED(objectName)
    buttonTitles  << tile;
    JCheckAbleButton* button = new JCheckAbleButton(tile);
    buttons.append(button);
//    button->setObjectName(objectName);
    button->setFixedSize(200, 60);
    tabLayout->insertWidget(tabLayout->count() - 1, button);
    connect(button, SIGNAL(clicked()), this, SLOT(setButtonChecked()));
//    widget->setObjectName(objectName);
    stackLayout->addWidget(widget);
}

QList<JCheckAbleButton*> JTabWidget::getButtons()
{
    return buttons;
}

void JTabWidget::setButtonChecked()
{
    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons.at(i) == sender())
        {
            buttons.at(i)->setChecked(true);
            stackLayout->setCurrentIndex(i);
            emit indexChanged(i);
        }
        else{
            buttons.at(i)->setChecked(false);
        }
    }
}

}   //namespace JNQTF
