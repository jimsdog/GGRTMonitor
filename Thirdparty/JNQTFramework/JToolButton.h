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

#ifndef __JToolButton_H__
#define __JToolButton_H__

#include <QMenu>
#include <QToolButton>

namespace JNQTF
{


class JToolButton : public QToolButton
{
    Q_OBJECT
public:
    JToolButton(QWidget* parent = 0);
    ~JToolButton();

    void setMenu(QMenu *menu);

public slots:
    void recover();

};

}   //namespace JNQTF

#endif // __JToolButton_H__
