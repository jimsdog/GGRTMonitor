#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T08:46:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GGRTMonitor
TEMPLATE = app


SOURCES +=\
    generated/GGConfig.cpp \
    generated/GGMonitorSession.cpp \
    generated/GGSmart.cpp \
    Views/loginview.cpp \
    Core/connectasynccallback.cpp \
    Core/ggapp.cpp \
    Core/ggcoordinator.cpp \
    Core/ggcoordinatori.cpp \
    Core/ggdispatcher.cpp \
    Core/ggiceevent.cpp \
    Core/logininfo.cpp \
    Core/monitorcallbacki.cpp \
    Views/ggmain.cpp \
    Core/main.cpp

HEADERS  += \
    generated/GGConfig.h \
    generated/GGMonitorSession.h \
    generated/GGSmart.h \
    Views/loginview.h \
    Core/connectasynccallback.h \
    Core/ggapp.h \
    Core/ggcommdefine.h \
    Core/ggcoordinator.h \
    Core/ggcoordinatori.h \
    Core/ggdispatcher.h \
    Core/ggiceevent.h \
    Core/logininfo.h \
    Core/monitorcallbacki.h \
    Views/ggmain.h

FORMS    += \
    Views/loginview.ui \
    Views/ggmain.ui

##--------------------------Added config

CONFIG += release

ICE_HOME = $$(ICE_HOME)

INCLUDEPATH   += .
INCLUDEPATH   += ./generated
INCLUDEPATH   += ./Core
INCLUDEPATH   += ./Views

!equals(ICE_HOME,"/usr"){
    INCLUDEPATH   += $$quote($$ICE_HOME/include)
}

win32{
#    ICON = resources/icons/logo.png
    DEFINES += WIN32_LEAN_AND_MEAN
#    RC_FILE = client.rc
    CONFIG(debug,debug|release){
        LIBS += "IceUtild.lib" \
                "Iced.lib" \
                "Glacier2d.lib"
    }
    else{
        LIBS += "IceUtil.lib" \
                "Ice.lib" \
                "Glacier2.lib"
    }
    ICE_x64suffix = $$(ICE_x64suffix)
    QMAKE_LIBDIR  += $$quote($$ICE_HOME/lib$$ICE_x64suffix)
}

RESOURCES += \
    res/ggres.qrc


