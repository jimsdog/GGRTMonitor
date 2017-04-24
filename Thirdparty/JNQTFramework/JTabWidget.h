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

#ifndef __JTabWidget_H__
#define __JTabWidget_H__

#include <QWidget>
#include <QStackedLayout>
#include <QBoxLayout>
#include "JCheckAbleButton.h"

namespace JNQTF
{

class JTabWidget : public QWidget
{
    Q_OBJECT

private:
    QList<JCheckAbleButton*> buttons;
    QList<QString> buttonTitles;

private:
    void initUI();
    void initConnect();

public:
    QWidget* tabTile;
    QBoxLayout* mainLayout;
    QStackedLayout* stackLayout;
    QVBoxLayout* tabLayout;
public:
    explicit JTabWidget(QWidget *parent = 0);
    QList<JCheckAbleButton*> getButtons();

signals:
        void indexChanged(int i);
public slots:
    void addWidget(const QString &tile, const QString &objectName, QWidget *widget);
    void setButtonChecked();
};

}   //namespace JNQTF

#endif // __JTabWidget_H__
