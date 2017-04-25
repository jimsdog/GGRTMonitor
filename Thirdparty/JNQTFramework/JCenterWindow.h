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

#ifndef __JCenterWindow_H__
#define __JCenterWindow_H__

#include <QFrame>
#include <QWidget>
#include <QStackedWidget>
#include <QResizeEvent>
#include <QPixmap>
#include "JNavgationBar.h"

namespace JNQTF
{

class JCenterWindow : public QFrame
{
    Q_OBJECT
private:
    JNavgationBar* navagationBar;
    QStackedWidget* stackWidget;
    QBoxLayout* navlayout;
    QVBoxLayout* mainLayout;
    int currentIndex;
    int preindex;
public:
    enum Alignment_Direction{
        TopLeft,
        TopCenter,
        TopRight,
        RightTop,
        RightCenter,
        RightBottom,
        BottomRight,
        BottomCenter,
        BottomLeft,
        LeftBottom,
        LeftCenter,
        LeftTop,
    };

    enum animation_Direction{
        animationTop,
        animationRight,
        animationBottom,
        animationLeft,
        animationTopLeft,
        animationTopRight,
        animationBottomRight,
        animationBottomLeft,
        animationCenter
    };

public:
    explicit JCenterWindow(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    void addWidget(const QString& tile, const QString &obejctName, QWidget* widget);
    void setAlignment(Alignment_Direction direction);
    JNavgationBar* getNavgationBar();
signals:

public slots:
    void switchscreen(const int index);
    void switchscreen();
    void swicthLayout(QBoxLayout::Direction direction);
    virtual void cloudAntimation(animation_Direction direction);
};

}   //namespace JNQTF

#endif // __JCenterWindow_H__
