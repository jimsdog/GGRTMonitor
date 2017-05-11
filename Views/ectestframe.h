#ifndef ECTESTFRAME_H
#define ECTESTFRAME_H

#include "ECLogoFrame.h"
#include "ECNavigationBar.h"
#include "ECAppBar.h"

#include "ECMainFrame.h"

#include <QFrame>

class ECTestFrame : public QFrame
{
    Q_OBJECT
private:
    ECFramework::ECLogoFrame        *m_logoframe;

    ECFramework::ECNavigationBar    *m_navigationbar;

    ECFramework::ECAppBar           *m_appbar;

    ECFramework::ECMainFrame        *m_mainframe;
public:
    explicit ECTestFrame(QWidget *parent = 0);

private:
    void initData();
    void initConnect();
    void initUI();
};

#endif // ECTESTFRAME_H
