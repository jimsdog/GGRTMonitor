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

#include "JCheckAbleButton.h"

namespace JNQTF
{

JCheckAbleButton::JCheckAbleButton(const QString& text)
{
    setFlat(true);
    setCheckable(true);
    setFixedSize(80, 60);
    setText(text);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("checkable");
}

}   //namespace JNQTF
