#include "ECSettingMenu.h"
#include "ECMainWindow.h"

namespace ECFramework
{

ECSettingMenu::ECSettingMenu(QWidget *parent)
    :QMenu(parent)
{
    setObjectName(QString("ECSettingMenu"));
}

void ECSettingMenu::initData()
{
    m_actionNames<< QString::fromLocal8Bit("关于")
                 << QString::fromLocal8Bit("检查更新")
                 << QString::fromLocal8Bit("退出");
}

void ECSettingMenu::initUI()
{
    QString qssstr = QLatin1String("QMenu#ECSettingMenu{\
                                   color: white;\
                                   background-color: qlineargradient(spread:pad, x1:-1, y1:0, x2:1 y2:0, stop:0 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                                   margin: 2px;\
                               }\
                               QMenu#ECSettingMenu::item {\
                                   height: 23px;\
                                   padding: 0px 25px 0px 20px;\
                                   background: qlineargradient(spread:pad, x1:-1, y1:0, x2:1 y2:0, stop:0 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                               }\
                               QMenu#ECSettingMenu::item:selected {\
                                   background-color: rgb(0, 82, 112);\
                                   border-left: 5px solid rgba(0, 211, 197, 255)\
                               }\
                               QMenu#ECSettingMenu::icon:checked {\
                                   background: rgb(0, 82, 112);\
                                   border: 1px inset gray;\
                                   position: absolute;\
                                   top: 1px;\
                                   right: 1px;\
                                   bottom: 1px;\
                                   left: 1px;\
                                }\
                               QMenu#ECSettingMenu::item:disabled\
                               {\
                                   background: rgb(125, 125, 125);\
                                   border: 1px inset gray;\
                                   position: absolute;\
                                   top: 1px;\
                                   right: 1px;\
                                   bottom: 1px;\
                                   left: 1px;\
                               }\
                               QMenu#ECSettingMenu::separator {\
                                   height: 2px;\
                                   background: lightblue;\
                                   margin-left: 10px;\
                                   margin-right: 5px;\
                               }\
                               QMenu#ECSettingMenu::indicator {\
                                   width: 13px;\
                                   height: 13px;\
                               }");
    setStyleSheet(qssstr);

    for(int i=0; i< m_actionNames.length() ; ++i)
    {
        m_actions.append(new QAction(m_actionNames.at(i), this));
        m_actionMaps[m_actionNames.at(i)] = m_actions.at(i);
    }
    addActions(m_actions);
}

void ECSettingMenu::initConnect()
{
    connect(m_actionMaps[QString::fromLocal8Bit("关于")], SIGNAL(triggered()), m_mainwindow, SLOT(settingmenuShowAbout()));
    connect(m_actionMaps[QString::fromLocal8Bit("检查更新")], SIGNAL(triggered()), m_mainwindow, SLOT(settingmenuShowAbout()));
    connect(m_actionMaps[QString::fromLocal8Bit("退出")], SIGNAL(triggered()), m_mainwindow, SLOT(close()));
}

void ECSettingMenu::Init(ECMainWindow *mainwindow)
{
    m_mainwindow = mainwindow;

    initData();
    initUI();
    initConnect();
}

}   //namespace ECFramework
