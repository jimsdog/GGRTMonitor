﻿#ifndef ECTESTFRAME_H
#define ECTESTFRAME_H

#include "ECLogoFrame.h"
#include "ECNavigationBar.h"
#include <QFrame>

class ECTestFrame : public QFrame
{
    Q_OBJECT
private:
    ECFramework::ECLogoFrame        *m_logoframe;

    ECFramework::ECNavigationBar    *m_navigationbar;
public:
    explicit ECTestFrame(QWidget *parent = 0);

private:
    void initData();
    void initConnect();
    void initUI();
};

#endif // ECTESTFRAME_H