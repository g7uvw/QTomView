#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"
#include "qtomviewview.h"
#include "TomView.h"

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
    // m_Empty = true;
    //m_Header.xsize = 0;
    // m_New = false;
    // m_XSlice = m_YSlice = m_ZSlice = m_BMPSlice = 0;

    m_Plane = XYPLANE;

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    child = createMdiChild();
    child->autoFillBackground();
    child->showMaximized();

    slicer = TOMSlicer::getInstance();

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
        volume.resize(volumeBytes);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        return;
    }
    TOMFILE.seek(0);                // seek to start so we're inn a known place
    TOMFILE.seek(sizeof(m_Header));  // seek to end of header
    TOMFILE.read((char*) &volume[0],volumeBytes);
    TOMFILE.close();

    child->setWindowTitle(QFileInfo(m_FileName).fileName());
    m_Plane = XYPLANE;
    m_CurrentSlice = m_Header.zsize/2;
    m_XSlice = m_Header.xsize / 2;
    m_YSlice = m_Header.ysize / 2;
    m_ZSlice = m_Header.zsize / 2;
    UpdateSlice();

}



void MainWindow::on_actionDown_Slice_triggered()
{
    switch (m_Plane)
    {
    case XYPLANE:
            if (m_ZSlice == 0)
                return;
            --m_ZSlice;
            break;
        case XZPLANE:
            if (m_YSlice == 0)
                return;
            --m_YSlice;
            break;
        case YZPLANE:
            if (m_XSlice == 0)
                return;
            --m_XSlice;
            break;
        }
        --m_CurrentSlice;

    if (m_CurrentSlice == 0)
        m_CurrentSlice = 0;

    UpdateSlice();

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

    UpdateSlice();
}


void MainWindow::UpdateSlice()
{
    CreateDefaultLookup();
    switch (m_Plane)
    {
    case YZPLANE:{
//      const std::vector<uint8_t>& TOMSlicer::YZSlice(const std::vector<uint8_t>& vol, size_t Xoffset, size_t xsize, size_t ysize, size_t zsize)
        const std::vector<uint8_t>&YZ = slicer->YZSlice(volume, m_XSlice, m_Header.xsize, m_Header.ysize, m_Header.zsize);

        QImage  YZSlice(YZ.data(),m_Header.ysize,m_Header.zsize,m_Header.ysize,QImage::Format_Indexed8);
        YZSlice.setColorTable(colorTable);

        //
//        QString imagePath(QStringLiteral("/Users/dm/Dropbox/TomFiles/YZPLANE.PNG"));
//        QImageWriter writer(imagePath);
//        writer.setFormat("png");
//        writer.write(YZSlice);
        //

        child->resize(YZSlice.width(),YZSlice.height());
        child->wipe();
        child->showSlice(YZSlice);
        break;}

    case XZPLANE:{
      //const std::vector<uint8_t>& TOMSlicer::XZSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Yoffset, size_t zsize)
        const std::vector<uint8_t>&XZ = slicer->XZSlice(volume, m_Header.xsize, m_Header.ysize, m_YSlice, m_Header.zsize);
        QImage  XZSlice(XZ.data(),m_Header.xsize,m_Header.zsize,m_Header.xsize,QImage::Format_Indexed8);
        XZSlice.setColorTable(colorTable);


//        QString imagePath(QStringLiteral("/Users/dm/Dropbox/TomFiles/XZPLANE.PNG"));
//        QImageWriter writer(imagePath);
//        writer.setFormat("png");
//        writer.write(XZSlice);


        child->resize(XZSlice.width(),XZSlice.height());
        child->showSlice(XZSlice);
        break;}

    default:
    case XYPLANE:{
        const std::vector<uint8_t>&XY = slicer->XYSlice(volume, m_Header.xsize, m_Header.ysize, m_ZSlice);
        QImage  XYSlice(XY.data(),m_Header.xsize,m_Header.ysize,m_Header.xsize,QImage::Format_Indexed8);
        XYSlice.setColorTable(colorTable);

        //
//        QString imagePath(QStringLiteral("/Users/dm/Dropbox/TomFiles/XYPLANE.PNG"));
//        QImageWriter writer(imagePath);
//        writer.setFormat("png");
//        writer.write(XYSlice);
        //

        child->resize(XYSlice.width(),XYSlice.height());
        child->showSlice(XYSlice);
        break;}
    }

}


void MainWindow::on_actionXY_Slice_triggered()
{
    m_Plane = XYPLANE;
    UpdateSlice();
}

void MainWindow::on_actionYZ_Slice_triggered()
{
    m_Plane = YZPLANE;
    UpdateSlice();
}

void MainWindow::on_actionXZ_Slice_triggered()
{
    m_Plane = XZPLANE;
    UpdateSlice();
}



QTomViewView *MainWindow::createMdiChild()
{
    QTomViewView *child = new QTomViewView;
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


void MainWindow::CreateDefaultLookup()
{
    QVector<QRgb> colorTable;
    for (int i = 0; i < 256; i++)
        colorTable.push_back(QColor(i, i, i).rgb());
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





void MainWindow::CreateBitmap()
{
    //    unsigned int m_YSize,m_XSize,m_ZSize;
    //    m_YSize = m_Header.ysize;
    //    m_XSize = m_Header.xsize;
    //    m_ZSize = m_Header.zsize;

    //    int XRoundupSize;
    //        if (m_XSize % 4)
    //            XRoundupSize = m_XSize + 4 - (m_XSize % 4);
    //        else
    //            XRoundupSize = m_XSize;
    //        if (m_BitmapArray != NULL)
    //            delete [] m_BitmapArray;
    //        if (m_BitmapBuffer != NULL)
    //            delete [] m_BitmapBuffer;
    //        m_BitmapBuffer = new unsigned char [m_YSize*XRoundupSize];
    //        m_BitmapArray = new unsigned char * [m_YSize];
    //        m_BitmapBufferSize = m_YSize*XRoundupSize;
    //        for (unsigned int a=0; a<m_YSize; ++a)
    //            m_BitmapArray[a] = &m_BitmapBuffer[a*XRoundupSize];
}


