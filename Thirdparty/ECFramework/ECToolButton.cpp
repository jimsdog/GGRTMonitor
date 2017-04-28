#include "ECToolButton.h"

namespace ECFramework
{

ECToolButton::ECToolButton(QWidget *parent)
    :QToolButton(parent)
{
    setObjectName("ECToolButton");

    initData();
    initUI();
    initConnect();
}

void ECToolButton::initData()
{
}

void ECToolButton::initUI()
{
    QString qssstr = QLatin1String("QToolButton{\
                                   background-color: transparent;\
                                   color: rgb(92, 113, 134);\
                               }\
                               QToolButton:hover{\
                                   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 82, 112, 255), stop:0.5 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                                   color: white;\
                                   border: 1px;\
                               }\
                               QToolButton:disabled{\
                                   background-color: gray;\
                                   border: 1px;\
                               }\
                               QToolButton[popupMode='1']\
                                   padding-right: 0px;\
                               }\
                               QToolButton::menu-button {\
                                   border: none;\
                               }\
                               QToolButton::menu-arrow {\
                                   image: none;\
                               }\
                               QToolButton::menu-indicator {\
                                   image: none;\
                               }\
                               QToolButton:open { /* when the button has its menu open */\
                                   background-color: rgb(0, 82, 112);\
                               }");

    setStyleSheet(qssstr);
}

void ECToolButton::initConnect()
{
}

void ECToolButton::SetButtonMenu(QMenu *menu)
{
    connect(menu, SIGNAL(aboutToHide()), this, SLOT(Recover()));
    QToolButton::setMenu(menu);
}

void ECToolButton::Recover()
{
#ifdef Q_OS_LINUX
    bool flag = this->rect().contains(this->mapFromGlobal(QCursor::pos()));
    this->setAttribute(Qt::WA_UnderMouse, flag);
    this->update();
#endif
}

}   //namespace ECFramework
