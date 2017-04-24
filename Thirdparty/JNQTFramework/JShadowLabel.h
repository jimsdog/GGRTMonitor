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

#ifndef __JShadowLabel_H__
#define __JShadowLabel_H__

#include <QLabel>


namespace JNQTF
{

class JShadowLabel : public QLabel
{
    Q_OBJECT
public:
    explicit JShadowLabel(const QString &text, QWidget *parent = 0);
    explicit JShadowLabel(QWidget *parent = 0);

signals:

public slots:

};

}   //namespace JNQTF

#endif // __JShadowLabel_H__
