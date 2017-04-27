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

#include "ECConfig.h"
#include "ECLogoFrame.h"
#include <QHBoxLayout>
#include <QImageReader>
#include <QImage>
#include <QLabel>

namespace ECFramework
{

ECLogoFrame* ECLogoFrame::m_instance = NULL;

ECLogoFrame::ECLogoFrame(QWidget *parent) :
    QFrame(parent)
{
    setObjectName(QString("ECLogoFrame"));
}

ECLogoFrame* ECLogoFrame::getInstace(QWidget *parent)
{
    if(!m_instance)
    {
        m_instance = new ECLogoFrame(parent);
    }
    return m_instance;
}

void ECLogoFrame::Init(QString imgpath, QString title, Array_Direction adirecton, int height, int width)
{
    m_imgpath = imgpath;
    m_title = title;
    m_adirecton = adirecton;
    m_height = height;
    m_width = width;

    initData();
    initUI();
    initConnect();
}

void ECLogoFrame::initData()
{
    if(m_height <= 0)
    {
        m_height = std::min(EC_TITLEBAR_HEIGHT, EC_LOGOFRAME_HEIGHT);
    }
    if(m_width <= 0)
    {
        m_width = EC_LOGOFRAME_WIDTH;
    }
    m_logolayout = new QBoxLayout(QBoxLayout::LeftToRight);
    m_logolayout->setParent(this);
}

void ECLogoFrame::initUI()
{
    setFixedHeight(m_height);
    setFixedWidth(m_width);

    if(m_logolayout == 0)
    {
        return;
    }
    if(m_adirecton == Horizontal)
    {
        m_logolayout->setDirection(QBoxLayout::LeftToRight);
    }
    else
    {
        m_logolayout->setDirection(QBoxLayout::TopToBottom);
    }
    bool isimageok = false;
    bool istitleok = false;
    QImageReader source(m_imgpath);
    if(source.canRead())
    {
        isimageok = true;
    }
    if(!m_title.isNull() && !m_title.isEmpty())
    {
        istitleok = true;
    }
    if(isimageok)
    {
        QLabel *imglabel = new QLabel(this);
        imglabel->setObjectName(QString("ECLogoFrameImglabel"));
        if(istitleok)
        {
            if(m_adirecton == Horizontal)
            {
                imglabel->setFixedSize(QSize(m_width/3, m_height));
            }
            else
            {
                imglabel->setFixedSize(QSize(m_width, m_height/2));
            }
        }
        else
        {
            imglabel->setFixedSize(QSize(m_width, m_height));
        }

        QImage *img = new QImage(m_imgpath);
        *img = img->scaled(imglabel->size()*0.95, Qt::KeepAspectRatio);
        imglabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        imglabel->setPixmap(QPixmap::fromImage(*img));

        m_logolayout->addWidget(imglabel);
    }

    if(istitleok)
    {
        QLabel *titlelabel = new QLabel(this);
        titlelabel->setObjectName(QString("ECLogoFrameTitlelabel"));

        QFont ft;
        ft.setFamily("Helvetica");
        ft.setPointSize(15);
        ft.setBold(true);
        titlelabel->setFont(ft);

        QPalette pa;
        pa.setColor(QPalette::WindowText,Qt::black);
        titlelabel->setPalette(pa);

        if(isimageok)
        {
            if(m_adirecton == Horizontal)
            {
                titlelabel->setFixedSize(QSize(2*m_width/3, m_height));
            }
            else
            {
                titlelabel->setFixedSize(QSize(m_width, m_height/2));
            }
        }
        else
        {
            titlelabel->setFixedSize(QSize(m_width, m_height));
        }
        titlelabel->setText(m_title);

        m_logolayout->addWidget(titlelabel);
    }

    m_logolayout->addStretch();
    m_logolayout->setContentsMargins(5, 0, 5, 0);
    m_logolayout->setSpacing(0);

    setLayout(m_logolayout);

    QString qssstr = QLatin1String("QFrame#ECLogoFrame{\
                                    background-color: rgba(255, 255, 224, 10%);\
                                    background-image: url(none);\
                                    background-repeat:repeat-xy;\
                               }");
    setStyleSheet(qssstr);
}

void ECLogoFrame::initConnect()
{

}


}   //namespace ECFramework

