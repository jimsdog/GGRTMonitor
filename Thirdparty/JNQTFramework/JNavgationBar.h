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

#ifndef __JNavgationBar_H__
#define __JNavgationBar_H__

#include <QFrame>
#include <QList>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "JCheckAbleButton.h"


namespace JNQTF
{

class JNavgationBar : public QFrame
{
    Q_OBJECT
private:
    QHBoxLayout* mainlayout_topLeft;
    QHBoxLayout* mainlayout_topCenter;
    QHBoxLayout* mainlayout_topRight;
    QHBoxLayout* mainlayout_bottomLeft;
    QHBoxLayout* mainlayout_bottomCenter;
    QHBoxLayout* mainlayout_bottomRight;
    QVBoxLayout* mainlayout_leftTop;
    QVBoxLayout* mainlayout_leftCenter;
    QVBoxLayout* mainlayout_leftBottom;
    QVBoxLayout* mainlayout_rightTop;
    QVBoxLayout* mainlayout_rightCenter;
    QVBoxLayout* mainlayout_rightBottom;
    int cIndex;
public:

    QList<JCheckAbleButton*> buttons;
    QList<QString> buttonTitles;
public:
    explicit JNavgationBar(QWidget *parent = 0);
    void initData();
    void initConnect();
    void initUI();
    int currentIndex();
    int count();
    void setCurrentIndex(int index);
    void addNavgationTile(const QString& tile, const QString &objectName);
    void setAlignment_topLeft();
    void setAlignment_topCenter();
    void setAlignment_topRight();
    void setAlignment_bottomLeft();
    void setAlignment_bottomCenter();
    void setAlignment_bottomRight();
    void setAlignment_leftTop();
    void setAlignment_leftCenter();
    void setAlignment_leftBottom();
    void setAlignment_rightTop();
    void setAlignment_rightCenter();
    void setAlignment_rightBottom();
signals:
    void indexChanged(int i);
private slots:
    void setButtonChecked();

};

}   //namespace JNQTF

#endif // __JNavgationBar_H__
