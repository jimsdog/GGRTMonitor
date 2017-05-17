#-------------------------------------------------
#
# Project created by QtCreator 2016-11-14T08:46:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

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
    Thirdparty/ECFramework/ECLogoFrame.cpp \
    Views/ectestframe.cpp \
    Thirdparty/ECFramework/ECNavigationBar.cpp \
    Thirdparty/ECFramework/ECNavigationButton.cpp \
    Thirdparty/ECFramework/ECToolButton.cpp \
    Thirdparty/ECFramework/ECSystemToolBar.cpp \
    Thirdparty/ECFramework/ECAppBar.cpp \
    Thirdparty/ECFramework/ECMainFrame.cpp \
    Thirdparty/ECFramework/ECFlyWidget.cpp \
    Thirdparty/ECFramework/ECMainWindow.cpp \
    Views/mainwindow.cpp \
    Thirdparty/ECFramework/ECSettingMenu.cpp \
    Thirdparty/ECFramework/ECLoading.cpp \
    Thirdparty/ECFramework/ECWaitDialog.cpp \
    Thirdparty/ECFramework/ECSpeech.cpp \
    Thirdparty/ECFramework/ECLightBoxWidget.cpp

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
    Thirdparty/ECFramework/ECLogoFrame.h \
    Thirdparty/ECFramework/ECConfig.h \
    Views/ectestframe.h \
    Thirdparty/ECFramework/ECNavigationBar.h \
    Thirdparty/ECFramework/ECNavigationButton.h \
    Thirdparty/ECFramework/ECToolButton.h \
    Thirdparty/ECFramework/ECSystemToolBar.h \
    Thirdparty/ECFramework/ECAppBar.h \
    Thirdparty/ECFramework/ECMainFrame.h \
    Thirdparty/ECFramework/ECFlyWidget.h \
    Thirdparty/ECFramework/ECMainWindow.h \
    Views/mainwindow.h \
    Thirdparty/ECFramework/ECSettingMenu.h \
    Thirdparty/ECFramework/ECLoading.h \
    Thirdparty/ECFramework/ECWaitDialog.h \
    Thirdparty/ECFramework/ECSpeech.h \
    Thirdparty/ECFramework/ECLightBoxWidget.h

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
INCLUDEPATH   += ./Thirdparty/ECFramework

!equals(ICE_HOME,"/usr"){
    INCLUDEPATH   += $$quote($$ICE_HOME/include)
}

win32{
#    ICON = resources/icons/logo.png
    DEFINES += WIN32_LEAN_AND_MEAN
    RC_FILE = app.rc
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

    QMAKE_CFLAGS -= -Zc:strictStrings
    QMAKE_CXXFLAGS -= -Zc:strictStrings
}

RESOURCES += \
    res/ggres.qrc

DISTFILES +=


