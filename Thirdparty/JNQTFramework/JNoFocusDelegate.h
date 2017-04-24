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

#ifndef __JNoFocusDelegate_H__
#define __JNoFocusDelegate_H__

#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QModelIndex>

namespace JNQTF
{


class JNoFocusDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit JNoFocusDelegate(QObject *parent = 0);
    void paint( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
signals:

public slots:

};

}   //namespace JNQTF

#endif // __JNoFocusDelegate_H__
