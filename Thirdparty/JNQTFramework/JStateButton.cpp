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

#include "JStateButton.h"

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    #include<QtCore/qmath.h>
#else
    #include <QtMath>
#endif

#include <QBitmap>

namespace JNQTF
{


JStateButton::JStateButton(const QString &ficon, const QString &bicon, int buttonFlag, QWidget *parent):
    QPushButton(parent), fStateIcon(ficon), bStateIcon(bicon), bflag(buttonFlag)
{
    state = 0;
    if(bflag == 0)
    {
        setIcon(QIcon(fStateIcon));
        setIconSize(QPixmap(fStateIcon).size());
    }
    else if (bflag == 1)
    {
        setText(fStateIcon);;
    }
    connect(this, SIGNAL(clicked()), this, SLOT(changeState()));
}

void JStateButton::changeState()
{
    state = qAbs(1 - state);
    if(state == 0){
        if(bflag == 0){
            setIcon(QIcon(fStateIcon));
            setMask(QBitmap(fStateIcon).mask());
        }
        else if(bflag == 1)
        {
            setText(fStateIcon);
        }

    }
    else if(state == 1)
    {
        if(bflag == 0){
            setIcon(QIcon(bStateIcon));
            setMask(QBitmap(bStateIcon).mask());
        }
        else if(bflag == 1)
        {
            setText(bStateIcon);
        }
    }
    emit stateChanged();
}

int JStateButton::getState()
{
    return state;
}

}   //namespace JNQTF
