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


#include <QPixmap>
#include <QEvent>
#include <QPaintEvent>
#include <QChildEvent>
#include <QPainter>
#include "ECLightBoxWidget.h"

namespace ECFramework
{

ECLightBoxWidget::ECLightBoxWidget(QWidget *parent, bool _folowToHeadWidget)
    : QWidget(parent)
    , m_isInUpdateSelf(false)
{
    Q_ASSERT_X(parent, "", Q_FUNC_INFO);

    if (_folowToHeadWidget) {
        while (parent->parentWidget() != 0) {
            parent = parent->parentWidget();
        }
        setParent(parent);
    }
    parent->installEventFilter(this);
    setVisible(false);
}

bool ECLightBoxWidget::eventFilter(QObject* _object, QEvent* _event)
{
    if (_event->type() == QEvent::ChildAdded) {
        QChildEvent* childEvent = dynamic_cast<QChildEvent*>(_event);
        if (childEvent->child() != this) {
            QWidget* parent = parentWidget();
            setParent(0);
            setParent(parent);
        }
    }
    if (isVisible()
        && _event->type() == QEvent::Resize) {
        updateSelf();
    }
    return QWidget::eventFilter(_object, _event);
}

void ECLightBoxWidget::paintEvent(QPaintEvent* _event)
{
    QPainter p;
    p.begin(this);
    p.drawPixmap(0, 0, width(), height(), m_parentWidgetPixmap);
    p.setBrush(QBrush(QColor(0, 0, 0, 170)));
    p.drawRect(0, 0, width(), height());
    p.end();

    QWidget::paintEvent(_event);
}

void ECLightBoxWidget::showEvent(QShowEvent* _event)
{
    updateSelf();

    QWidget::showEvent(_event);
}

void ECLightBoxWidget::updateSelf()
{
    if (!m_isInUpdateSelf) {
        m_isInUpdateSelf = true;

        {
            hide();
            resize(parentWidget()->size());
            m_parentWidgetPixmap = grabParentWidgetPixmap();
            show();
        }

        m_isInUpdateSelf = false;
    }
}

QPixmap ECLightBoxWidget::grabParentWidgetPixmap() const
{
    QPixmap parentWidgetPixmap;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    parentWidgetPixmap = parentWidget()->grab();
#else
    parentWidgetPixmap = QPixmap::grabWidget(parentWidget());
#endif

    return parentWidgetPixmap;
}

}   //namespace ECFramework
