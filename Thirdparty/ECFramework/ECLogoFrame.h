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

#ifndef __ECLogoFrame_H__
#define __ECLogoFrame_H__

#include <QFrame>
#include <QBoxLayout>


namespace ECFramework
{


class ECLogoFrame : public QFrame
{
    Q_OBJECT
public:
    enum Array_Direction{
        Horizontal,
        Vertical
    };

private:
    QString             m_title;
    QString             m_imgpath;
    Array_Direction     m_adirecton;

    int                 m_height;
    int                 m_width;

    QBoxLayout*         m_logolayout;
public:
    static ECLogoFrame* m_instance;

private:
    void initData();
    void initConnect();
    void initUI();

public:
    explicit ECLogoFrame(QWidget *parent = 0);
    static ECLogoFrame* getInstace(QWidget *parent = 0);

    void Init(QString imgpath, QString title, Array_Direction adirecton = Horizontal, int height = 0, int width = 0);


signals:

public slots:


};

}   //namespace ECFramework

#endif // __ECLogoFrame_H__
