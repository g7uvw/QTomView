#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"
#include "qtomv_view.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QtWidgets>
#include <QByteArray>
#include <QImageWriter>
#include <iterator>
#include <vector>
#include <iostream>
#include <fstream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_FilePath((""))
  , m_FileName((""))
  , m_MinX(0)
  , m_MaxX(0)
  , m_MinY(0)
  , m_MaxY(0)
  , m_MinZ(0)
  , m_MaxZ(0)
  , m_CurrentSlice(0)
  , m_CropTags(false)
{
    ui->setupUi(this);
    m_Plane = XYPLANE;
    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    view_area = createMdiChild();
    view_area->autoFillBackground();
    view_area->showMaximized();
    //slicer = TOMSlicer::getInstance();

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionOpen_triggered()
{
    m_FileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.tom)"));
    QFile TOMFILE(m_FileName);
    if (!TOMFILE.open(QIODevice::ReadOnly)) Alert("Cannot open file","File open error.");
    qint64 bytes = TOMFILE.read((char*) &m_Header, sizeof(m_Header));
    if (bytes != sizeof(m_Header)) Alert("Cannot read header", "File open error.");

    size_t volumeBytes = m_Header.xsize*m_Header.ysize *m_Header.zsize;
    std::cerr << "Trying to allocate vector with storage for  " << volumeBytes << " bytes." << std::endl;
    try {
        view_area->volume.resize(volumeBytes);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        return;
    }
    TOMFILE.seek(0);                // seek to start so we're in a known place
    TOMFILE.seek(sizeof(m_Header));  // seek to end of header
    TOMFILE.read((char*) &view_area->volume[0],volumeBytes);
    TOMFILE.close();

    view_area->ReceiveHeader(m_Header);
    view_area->setWindowTitle(QFileInfo(m_FileName).fileName());
    m_Plane = XYPLANE;
    m_CurrentSlice = m_Header.zsize/2;
    m_XSlice = m_Header.xsize / 2;
    m_YSlice = m_Header.ysize / 2;
    m_ZSlice = m_Header.zsize / 2;
    
    QTomV_View::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    view_area->UpdateSlice(Slice);
}



void MainWindow::on_actionDown_Slice_triggered()
{
    QTomV_View::s_Slice Slice;
    
    // Set some defaults in case things go wrong.
    Slice.Plane  = XYPLANE;
    Slice.XSlice = 0;
    Slice.YSlice = 0;
    Slice.ZSlice = 0;
        
    switch (m_Plane)
    {
    case XYPLANE:
            Slice.Plane = XYPLANE;
            if (m_ZSlice == 0)
            {
                Slice.ZSlice = 0;
                return;
            }
            --m_ZSlice;
            Slice.ZSlice = m_ZSlice;
            break;
            
        case XZPLANE:
            Slice.Plane = XZPLANE;
            if (m_YSlice == 0)
            {
                Slice.YSlice = 0;
                return;
            }
            --m_YSlice;
            Slice.YSlice = m_YSlice;
            break;
            
        case YZPLANE:
            Slice.Plane = YZPLANE;
            if (m_XSlice == 0)
            {
                Slice.XSlice = 0;
                return;
            }
            --m_XSlice;
            Slice.XSlice = m_XSlice;
            break;
        }
        --m_CurrentSlice;

    if (m_CurrentSlice == 0)
        m_CurrentSlice = 0;

    view_area->UpdateSlice(Slice);

}

void MainWindow::on_actionUpSlice_triggered()
{
    switch (m_Plane	)
        {
        case XYPLANE:
            if (m_ZSlice == m_Header.zsize-1)
                return;
            ++m_ZSlice;
            break;
        case XZPLANE:
            if (m_YSlice == m_Header.ysize-1)
                return;
            ++m_YSlice;
            break;
        case YZPLANE:
            if (m_XSlice == m_Header.xsize-1)
                return;
            ++m_XSlice;
            break;
        }
        ++m_CurrentSlice;
   
    QTomV_View::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    view_area->UpdateSlice(Slice);
}



void MainWindow::on_actionXY_Slice_triggered()
{
    m_Plane = XYPLANE;
    QTomV_View::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    view_area->UpdateSlice(Slice);
}

void MainWindow::on_actionYZ_Slice_triggered()
{
    m_Plane = YZPLANE;
    QTomV_View::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    view_area->UpdateSlice(Slice);
}

void MainWindow::on_actionXZ_Slice_triggered()
{
    m_Plane = XZPLANE;
    QTomV_View::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    view_area->UpdateSlice(Slice);
}



QTomV_View *MainWindow::createMdiChild()
{
    QTomV_View *child = new QTomV_View;
    mdiArea->addSubWindow(child);
    return child;
}




void MainWindow::Texit(QString Message)
{
    QMessageBox msgBox;
    msgBox.setText(Message);
    msgBox.exec();
    qApp->exit();
}
void MainWindow::Alert(QString Message, QString Title)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(Title);
    msgBox.setText(Message);
    msgBox.exec();
}




void MainWindow::on_actionInformation_triggered()
{
    InfoDialog *id = new InfoDialog(m_Header);
    id->show();
}




void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_action25_triggered()
{

}

void MainWindow::on_action50_triggered()
{

}

void MainWindow::on_action100_triggered()
{

}

void MainWindow::on_action200_triggered()
{

}

void MainWindow::on_action300_triggered()
{

}




