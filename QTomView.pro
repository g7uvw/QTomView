#-------------------------------------------------
#
# Project created by QtCreator 2015-01-30T11:49:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTomView
TEMPLATE = app
QMAKE_MAC_SDK = macosx10.11

SOURCES += main.cpp\
        mainwindow.cpp \
    infodialog.cpp \
    qtomviewview.cpp

HEADERS  += mainwindow.h \
    TomHeader.h \
    TomView.h \
    infodialog.h \
    qtomviewview.h

FORMS    += mainwindow.ui \
    infodialog.ui

RESOURCES += \
    qtomviewresources.qrc
