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
    Core/main.cpp \
    Views/util/jniconhelper.cpp \
    Views/util/jnmessagebox.cpp \
    Views/util/jnappconfig.cpp \
    Views/util/jnhelper.cpp \
    Views/util/jninputbox.cpp \
    Util/jnqtlogger.cpp \
    Thirdparty/JNQTFramework/JUtil.cpp \
    Thirdparty/JNQTFramework/JToolButton.cpp \
    Thirdparty/JNQTFramework/JTitleBar.cpp \
    Thirdparty/JNQTFramework/JCheckAbleButton.cpp \
    Thirdparty/JNQTFramework/JStateButton.cpp \
    Thirdparty/JNQTFramework/JFlyWidget.cpp \
    Thirdparty/JNQTFramework/JBasePushButton.cpp \
    Thirdparty/JNQTFramework/JBaseDialog.cpp \
    Thirdparty/JNQTFramework/JTabWidget.cpp \
    Thirdparty/JNQTFramework/JWigglyWidget.cpp \
    Thirdparty/JNQTFramework/JShadowLabel.cpp \
    Thirdparty/JNQTFramework/JNoFocusDelegate.cpp \
    Thirdparty/JNQTFramework/JNavgationBar.cpp

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
    Views/ggmain.h \
    Views/util/jniconhelper.h \
    Views/util/jnmessagebox.h \
    Views/util/jnappconfig.h \
    Views/util/jnhelper.h \
    Views/util/jninputbox.h \
    Util/jnqtlogger.h \
    Thirdparty/JNQTFramework/JUtil.h \
    Thirdparty/JNQTFramework/JToolButton.h \
    Thirdparty/JNQTFramework/JTitleBar.h \
    Thirdparty/JNQTFramework/JCheckAbleButton.h \
    Thirdparty/JNQTFramework/JStateButton.h \
    Thirdparty/JNQTFramework/JFlyWidget.h \
    Thirdparty/JNQTFramework/JBasePushButton.h \
    Thirdparty/JNQTFramework/JBaseDialog.h \
    Thirdparty/JNQTFramework/JTabWidget.h \
    Thirdparty/JNQTFramework/JWigglyWidget.h \
    Thirdparty/JNQTFramework/JShadowLabel.h \
    Thirdparty/JNQTFramework/JNoFocusDelegate.h \
    Thirdparty/JNQTFramework/JNavgationBar.h

FORMS    += \
    Views/loginview.ui \
    Views/ggmain.ui \
    Views/util/jnmessagebox.ui \
    Views/util/jninputbox.ui

##--------------------------Added config

CONFIG += release

ICE_HOME = $$(ICE_HOME)

INCLUDEPATH   += .
INCLUDEPATH   += ./generated
INCLUDEPATH   += ./Core
INCLUDEPATH   += ./Util
INCLUDEPATH   += ./Views
INCLUDEPATH   += ./Views/util

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

DISTFILES +=


