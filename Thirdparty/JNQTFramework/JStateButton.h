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

#ifndef __JStateButton_H__
#define __JStateButton_H__

#include <QPushButton>


namespace JNQTF
{

class JStateButton : public QPushButton
{
    Q_OBJECT
private:
    QString fStateIcon;
    QString bStateIcon;
    int state;
    int bflag;
private slots:
    void changeState();
public:
    explicit JStateButton(const QString &ficon, const QString &bicon, int buttonFlag = 0, QWidget *parent = 0);
    int getState();
signals:
    void stateChanged();
public slots:

};

}   //namespace JNQTF

#endif // __JStateButton_H__
