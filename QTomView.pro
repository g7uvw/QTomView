#-------------------------------------------------
#
# Project created by QtCreator 2015-01-30T11:49:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTomView
TEMPLATE = app
QMAKE_CXXFLAGS += -Wall

SOURCES += main.cpp\
        mainwindow.cpp \
    infodialog.cpp \
    qtomv_view.cpp \
    tomslicer.cpp

HEADERS  += mainwindow.h \
    TomHeader.h \
    infodialog.h \
    qtomv_view.h \
    tomslicer.h

FORMS    += mainwindow.ui \
    infodialog.ui

RESOURCES += \
    qtomviewresources.qrc
