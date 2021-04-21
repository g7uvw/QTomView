/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionOrigin;
    QAction *actionSlice;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionClear;
    QAction *actionConstrast;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *action9;
    QAction *action10;
    QAction *action15;
    QAction *action20;
    QAction *action30;
    QAction *actionEnable;
    QAction *actionDisable;
    QAction *actionInformation;
    QAction *action25;
    QAction *action50;
    QAction *action100;
    QAction *action200;
    QAction *action300;
    QAction *actionXY_Slice;
    QAction *actionYZ_Slice;
    QAction *actionXZ_Slice;
    QAction *actionUpSlice;
    QAction *actionDown_Slice;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuZoom;
    QMenu *menuTags;
    QMenu *menuRadius;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/icons/Open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionOrigin = new QAction(MainWindow);
        actionOrigin->setObjectName(QStringLiteral("actionOrigin"));
        actionSlice = new QAction(MainWindow);
        actionSlice->setObjectName(QStringLiteral("actionSlice"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionConstrast = new QAction(MainWindow);
        actionConstrast->setObjectName(QStringLiteral("actionConstrast"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/icons/Color_wheel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConstrast->setIcon(icon1);
        action2 = new QAction(MainWindow);
        action2->setObjectName(QStringLiteral("action2"));
        action3 = new QAction(MainWindow);
        action3->setObjectName(QStringLiteral("action3"));
        action4 = new QAction(MainWindow);
        action4->setObjectName(QStringLiteral("action4"));
        action5 = new QAction(MainWindow);
        action5->setObjectName(QStringLiteral("action5"));
        action6 = new QAction(MainWindow);
        action6->setObjectName(QStringLiteral("action6"));
        action7 = new QAction(MainWindow);
        action7->setObjectName(QStringLiteral("action7"));
        action8 = new QAction(MainWindow);
        action8->setObjectName(QStringLiteral("action8"));
        action9 = new QAction(MainWindow);
        action9->setObjectName(QStringLiteral("action9"));
        action10 = new QAction(MainWindow);
        action10->setObjectName(QStringLiteral("action10"));
        action15 = new QAction(MainWindow);
        action15->setObjectName(QStringLiteral("action15"));
        action20 = new QAction(MainWindow);
        action20->setObjectName(QStringLiteral("action20"));
        action30 = new QAction(MainWindow);
        action30->setObjectName(QStringLiteral("action30"));
        actionEnable = new QAction(MainWindow);
        actionEnable->setObjectName(QStringLiteral("actionEnable"));
        actionDisable = new QAction(MainWindow);
        actionDisable->setObjectName(QStringLiteral("actionDisable"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QStringLiteral("actionInformation"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/icons/Info.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInformation->setIcon(icon2);
        action25 = new QAction(MainWindow);
        action25->setObjectName(QStringLiteral("action25"));
        action50 = new QAction(MainWindow);
        action50->setObjectName(QStringLiteral("action50"));
        action100 = new QAction(MainWindow);
        action100->setObjectName(QStringLiteral("action100"));
        action200 = new QAction(MainWindow);
        action200->setObjectName(QStringLiteral("action200"));
        action300 = new QAction(MainWindow);
        action300->setObjectName(QStringLiteral("action300"));
        actionXY_Slice = new QAction(MainWindow);
        actionXY_Slice->setObjectName(QStringLiteral("actionXY_Slice"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/icons/XY.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionXY_Slice->setIcon(icon3);
        actionYZ_Slice = new QAction(MainWindow);
        actionYZ_Slice->setObjectName(QStringLiteral("actionYZ_Slice"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/icons/YZ.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionYZ_Slice->setIcon(icon4);
        actionXZ_Slice = new QAction(MainWindow);
        actionXZ_Slice->setObjectName(QStringLiteral("actionXZ_Slice"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/icons/XZ.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionXZ_Slice->setIcon(icon5);
        actionUpSlice = new QAction(MainWindow);
        actionUpSlice->setObjectName(QStringLiteral("actionUpSlice"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/icons/Up.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpSlice->setIcon(icon6);
        actionDown_Slice = new QAction(MainWindow);
        actionDown_Slice->setObjectName(QStringLiteral("actionDown_Slice"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icons/icons/Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDown_Slice->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuZoom = new QMenu(menuView);
        menuZoom->setObjectName(QStringLiteral("menuZoom"));
        menuTags = new QMenu(menuBar);
        menuTags->setObjectName(QStringLiteral("menuTags"));
        menuRadius = new QMenu(menuTags);
        menuRadius->setObjectName(QStringLiteral("menuRadius"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTags->menuAction());
        menu_File->addAction(actionOpen);
        menu_File->addSeparator();
        menu_File->addAction(actionExport);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menuEdit->addAction(actionCopy);
        menuView->addAction(actionOrigin);
        menuView->addAction(actionSlice);
        menuView->addAction(menuZoom->menuAction());
        menuView->addAction(actionInformation);
        menuZoom->addAction(action25);
        menuZoom->addAction(action50);
        menuZoom->addAction(action100);
        menuZoom->addAction(action200);
        menuZoom->addAction(action300);
        menuTags->addAction(actionLoad);
        menuTags->addAction(actionSave);
        menuTags->addAction(actionClear);
        menuTags->addSeparator();
        menuTags->addAction(menuRadius->menuAction());
        menuTags->addAction(actionEnable);
        menuTags->addAction(actionDisable);
        menuRadius->addAction(actionConstrast);
        menuRadius->addAction(action2);
        menuRadius->addAction(action3);
        menuRadius->addAction(action4);
        menuRadius->addAction(action5);
        menuRadius->addAction(action6);
        menuRadius->addAction(action7);
        menuRadius->addAction(action8);
        menuRadius->addAction(action9);
        menuRadius->addAction(action10);
        menuRadius->addAction(action15);
        menuRadius->addAction(action20);
        menuRadius->addAction(action30);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionConstrast);
        toolBar->addSeparator();
        toolBar->addAction(actionUpSlice);
        toolBar->addAction(actionDown_Slice);
        toolBar->addAction(actionXY_Slice);
        toolBar->addAction(actionXZ_Slice);
        toolBar->addAction(actionYZ_Slice);
        toolBar->addSeparator();
        toolBar->addAction(actionInformation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        actionExport->setText(QApplication::translate("MainWindow", "Export", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
        actionOrigin->setText(QApplication::translate("MainWindow", "Origin", Q_NULLPTR));
        actionSlice->setText(QApplication::translate("MainWindow", "Slice", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        actionConstrast->setText(QApplication::translate("MainWindow", "Contrast/Brightness", Q_NULLPTR));
        action2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        action3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        action4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        action5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        action6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        action7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        action8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        action9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        action10->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        action15->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        action20->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        action30->setText(QApplication::translate("MainWindow", "30", Q_NULLPTR));
        actionEnable->setText(QApplication::translate("MainWindow", "Enable", Q_NULLPTR));
        actionDisable->setText(QApplication::translate("MainWindow", "Disable", Q_NULLPTR));
        actionInformation->setText(QApplication::translate("MainWindow", "Information", Q_NULLPTR));
        action25->setText(QApplication::translate("MainWindow", "25%", Q_NULLPTR));
        action50->setText(QApplication::translate("MainWindow", "50%", Q_NULLPTR));
        action100->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        action200->setText(QApplication::translate("MainWindow", "200%", Q_NULLPTR));
        action300->setText(QApplication::translate("MainWindow", "300%", Q_NULLPTR));
        actionXY_Slice->setText(QApplication::translate("MainWindow", "XY Slice", Q_NULLPTR));
        actionYZ_Slice->setText(QApplication::translate("MainWindow", "YZ_Slice", Q_NULLPTR));
        actionXZ_Slice->setText(QApplication::translate("MainWindow", "XZ Slice", Q_NULLPTR));
        actionUpSlice->setText(QApplication::translate("MainWindow", "Up", Q_NULLPTR));
        actionDown_Slice->setText(QApplication::translate("MainWindow", "Down Slice", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuView->setTitle(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        menuZoom->setTitle(QApplication::translate("MainWindow", "Zoom", Q_NULLPTR));
        menuTags->setTitle(QApplication::translate("MainWindow", "Tags", Q_NULLPTR));
        menuRadius->setTitle(QApplication::translate("MainWindow", "Radius", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
