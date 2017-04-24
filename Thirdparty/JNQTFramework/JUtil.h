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

#ifndef __JUtil_H__
#define __JUtil_H__
#include <stdio.h>
#include <stdlib.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QApplication>
#include <QFontDatabase>

namespace JNQTF
{

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    void loadFonts(QApplication& app);
#endif


QString getQssFromFile(QString filename);
QString readFile(const QString filename);
void setSkinForApp(QString filename);

}   //namespace JNQTF

#endif // __JUtil_H__
