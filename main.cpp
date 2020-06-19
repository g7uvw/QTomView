#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationVersion("2.0");
    a.setOrganizationDomain("http://qmxmt.com");
    a.setOrganizationName("Queen Mary XMT Facility");
    a.setApplicationName("TomView-2");
    MainWindow w;
    w.setWindowTitle("TomView-2");
    w.show();

    return a.exec();
}


