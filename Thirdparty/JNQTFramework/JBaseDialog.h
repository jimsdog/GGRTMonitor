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

#ifndef __JBaseDialog_H__
#define __JBaseDialog_H__

#include <QDialog>
#include <QMouseEvent>
#include <QShowEvent>
#include <QCloseEvent>
#include "JTitleBar.h"

namespace JNQTF
{

class JBaseDialog : public QDialog
{
    Q_OBJECT
private:
    QPoint dragPosition;

private:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    JTitleBar* titlebar;

protected:
    void showEvent(QShowEvent * event);
    void closeEvent(QCloseEvent * event);
public:
    QSize normalSize;

public:
    explicit JBaseDialog(QWidget *parent = 0);
    void initData();
    void initUI();
    void initConnect();
    JTitleBar* getTitleBar();

signals:

public slots:
   virtual void animationClose();
};

}   //namespace JNQTF

#endif // __JBaseDialog_H__
