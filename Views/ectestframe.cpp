#include "ectestframe.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDir>


ECTestFrame::ECTestFrame(QWidget *parent)
    :QFrame(parent)
{
    setObjectName(QString("ECTestFrame"));
    initData();
    initUI();
    initConnect();
}

void ECTestFrame::initData()
{
    m_logoframe = ECFramework::ECLogoFrame::getInstace(this);
    m_navigationbar = ECFramework::ECNavigationBar::getInstace(this);
    m_appbar = ECFramework::ECAppBar::getInstace(this);
}

void ECTestFrame::initUI()
{
    QString qssstr = QLatin1String("QFrame#ECTestFrame{\
                                   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 82, 112, 255), stop:0.5 rgba(0, 211, 197, 255), stop:1 rgba(0, 82, 112, 255));\
                                   background-image: url(none);\
                                   background-repeat:repeat-xy;\
                               }");
    setStyleSheet(qssstr);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    setMaximumSize(desktopWidget->availableGeometry().size());

    resize(desktopWidget->availableGeometry().size()* 0.6);

    QString apppath = QDir::currentPath();
    QString appimgpath = apppath + "/Images/logogoogol.png";
    QString title = QString::fromLocal8Bit("重庆固高");

    m_logoframe->Init(appimgpath, title);
    //m_logoframe->Init(appimgpath, QString("Test1Test2Test3Test4Test5Test6"));
    //m_logoframe->Init(appimgpath, QString());
    //m_logoframe->Init(QString(), QString());

    m_navigationbar->AddNavgationButton(apppath + "/Images/icons/dark/appbar.home.png", QString::fromLocal8Bit("主屏"));

    m_navigationbar->AddNavgationButton(apppath + "/Images/icons/dark/appbar.cog.png", QString::fromLocal8Bit("设置"));

    m_navigationbar->ResetLayout();

    QVBoxLayout* mainvlayout = new QVBoxLayout(this);
    QHBoxLayout* mainhlayout = new QHBoxLayout(this);
    mainhlayout->addWidget(m_logoframe);

    mainhlayout->addWidget(m_navigationbar);

    mainhlayout->addStretch();

    mainhlayout->addWidget(m_appbar);



    mainhlayout->setContentsMargins(0, 0, 0, 0);
    mainhlayout->setSpacing(0);

    mainvlayout->addLayout(mainhlayout);
    mainvlayout->addStretch();
    mainvlayout->setContentsMargins(0, 0, 0, 0);
    mainvlayout->setSpacing(0);
    setLayout(mainvlayout);
}

void ECTestFrame::initConnect()
{

}
