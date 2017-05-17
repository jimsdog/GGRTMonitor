/****************************************************************************
**
** Copyright (C) 2017 JIMSDOG
**
** ECFramework is a frameworke based on Qt5.3, you will be more efficient with it.
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

#ifndef __ECLIGHTBOXWIDGET_H__
#define __ECLIGHTBOXWIDGET_H__

#include <QWidget>

namespace ECFramework
{

class ECLightBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ECLightBoxWidget(QWidget *parent = 0, bool _folowToHeadWidget = false);

protected:
    bool eventFilter(QObject* _object, QEvent* _event);

    void paintEvent(QPaintEvent* _event);

    void showEvent(QShowEvent* _event);

private:
    void updateSelf();

    bool m_isInUpdateSelf;

    QPixmap grabParentWidgetPixmap() const;

    QPixmap m_parentWidgetPixmap;

signals:

public slots:
};

}   //namespace ECFramework

#endif // __ECLIGHTBOXWIDGET_H__
