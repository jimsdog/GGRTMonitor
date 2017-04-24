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

#include "JShadowLabel.h"
#include <QGraphicsDropShadowEffect>

namespace JNQTF
{

JShadowLabel::JShadowLabel(const QString &text, QWidget *parent) :
    QLabel(text, parent)
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::darkGreen);
    shadow_effect->setBlurRadius(8);
    setGraphicsEffect(shadow_effect);
}

JShadowLabel::JShadowLabel(QWidget *parent) :
    QLabel(parent)
{
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(-5, 5);
    shadow_effect->setColor(Qt::darkGreen);
    shadow_effect->setBlurRadius(8);
    setGraphicsEffect(shadow_effect);
}

}   //namespace JNQTF
