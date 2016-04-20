#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"
#include"qtomviewview.h"
#include "TomView.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QtWidgets>
#include <QByteArray>



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
  , m_Im(NULL)
  , m_ImBuffer(NULL)
  , m_ImRow(NULL)
  , m_CurrentSlice(0)
  , m_CropTags(false)
{
    ui->setupUi(this);
    m_Empty = true;
    m_Header.xsize = 0;
    m_New = false;
    m_XSlice = m_YSlice = m_ZSlice = m_BMPSlice = 0;
    m_BitmapArray = NULL;
    m_BitmapBuffer = NULL;
    m_Plane = m_BMPPlane = XYPLANE;

    mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    child = createMdiChild();
    child->autoFillBackground();
    child->showMaximized();

    //StartMessage();
}


MainWindow::~MainWindow()
{
    int a;
        if (m_Im)
        {
            delete m_Im;
            delete m_ImRow;
            for (a=0; a<m_Header.zsize; ++a)
                delete m_ImBuffer[a];
            delete m_ImBuffer;
        }
    delete ui;
}


void MainWindow::AllocateMemory()
{
    int a,b;
    long Volume = (long)m_Header.xsize*m_Header.ysize*m_Header.zsize;
    long yzArea = (long)m_Header.ysize*m_Header.zsize;
    long xyArea = (long)m_Header.xsize*m_Header.ysize;

    // buffers already exist - lose them.
    if (m_Im)
    {
        delete m_Im;
        delete m_ImRow;
        for (a=0; a<m_Header.zsize; ++a)
            delete m_ImBuffer[a];
        delete m_ImBuffer;
    }

    // do we have any enough memory to load a slice?
    if ((m_ImBuffer = new unsigned char*[m_Header.zsize]) == NULL)
        Texit("Insufficient Memory");

    // make an array of XY arrays, or else fail if we don't have the memory.
    for (a=0; a<m_Header.zsize; ++a)
        {
            if ((m_ImBuffer[a] = new unsigned char[xyArea]) == NULL)
            Texit("Insufficient Memory");
        }

    // do we have space for a YZ Slice?
    if ((m_ImRow = new unsigned char*[yzArea]) == NULL)
        Texit("Insufficient Memory");

    // do we have space for an array of arrays?
    if ((m_Im = new unsigned char**[m_Header.zsize]) == NULL)
        Texit("Insufficient Memory");

    for (a = 0; a < m_Header.zsize; ++a)
        {
            for (b = 0; b < m_Header.ysize; ++b)
                {
                    m_ImRow[a*m_Header.ysize + b] = &(m_ImBuffer[a][b * m_Header.xsize]);
                }

            m_Im[a] = &m_ImRow[a * m_Header.ysize];
        }
}

void MainWindow::StartMessage()
{
    QString Message;
    Message += "The Mucat X-ray microtomography research facility ";
    Message += "is designed, run and under constant development by ";
    Message += "Dr Graham R Davis.\n";
    Message += "\n";
    Message += "Publication of results is positively encouraged and ";
    Message += "is essential for continued progress.  However, ";
    Message += "no images or data derived from the use of this ";
    Message += "facility may be published in any form without ";
    Message += "permission and due recognition. ";
    Message += "\n\nPlease contact me if you are using this system,";
    Message += " directly or indirectly, or if you wish to do so.";
    Message += "\nEmail:  G.R.Davis@microtomography.org\n\n";
    Message += "See www.microtomography.org for details.\n";

    QMessageBox msgBox;
    msgBox.setText(Message);
    msgBox.exec();
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

void MainWindow::on_actionOpen_triggered()
{
    unsigned int z, Area;
    m_FileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.tom)"));
    QFile TOMFILE(m_FileName);
    if (!TOMFILE.open(QIODevice::ReadOnly)) Alert("Cannot open file","File open error.");
    qint64 bytes = TOMFILE.read((char*) &m_Header, sizeof(m_Header));
    if (bytes != sizeof(m_Header)) Alert("Cannot read header", "File open error.");

    AllocateMemory();
    Area = m_Header.xsize*m_Header.ysize;
            for (z=0; z<m_Header.zsize; ++z)
                TOMFILE.read((char*)m_ImBuffer[z], Area);
    TOMFILE.close();

    m_YSize = m_YDim = m_Header.ysize;
    m_XSize = m_XDim = m_Header.xsize;
    m_ZSize = m_ZDim = m_Header.zsize;

    m_Plane = XYPLANE;
    CreateDefaultLookup();
    unsigned int centralslice = m_CurrentSlice = m_ZSlice = (m_Header.num_slices / 2);
    QImage  CentralXYSlice(m_ImBuffer[centralslice],m_Header.xsize,m_Header.ysize,m_Header.xsize,QImage::Format_Indexed8);

    CentralXYSlice.setColorTable(colorTable);
    child->resize(m_Header.xsize,m_Header.ysize);
    child->showSlice(CentralXYSlice);
    child->setWindowTitle(QFileInfo(m_FileName).fileName());
}

unsigned char *** MainWindow::GetIm()
{
    return m_Im;
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

void MainWindow::on_actionDown_Slice_triggered()
{
    if (m_CurrentSlice == 1)
        m_CurrentSlice = 0;
    else
        m_CurrentSlice--;
    QImage  Slice(m_ImBuffer[m_CurrentSlice],m_Header.xsize,m_Header.ysize,m_Header.xsize,QImage::Format_Indexed8);

    child->showSlice(Slice);
}

void MainWindow::on_actionUpSlice_triggered()
{
    if(m_CurrentSlice == m_Header.num_slices - 1)
        m_CurrentSlice = m_Header.num_slices;
    else
        m_CurrentSlice++;
    QImage  Slice(m_ImBuffer[m_CurrentSlice],m_Header.xsize,m_Header.ysize,m_Header.xsize,QImage::Format_Indexed8);
    child->showSlice(Slice);
}

void MainWindow::on_actionXY_Slice_triggered()
{
    m_Plane = XYPLANE;
    Resize();
    CreateBitmap();
    UpdateSlice();
}

void MainWindow::on_actionYZ_Slice_triggered()
{
    m_Plane = YZPLANE;
    Resize();
    CreateBitmap();
    UpdateSlice();
}

void MainWindow::on_actionXZ_Slice_triggered()
{
    m_Plane = XZPLANE;
    Resize();
    CreateBitmap();
    UpdateSlice();
}

void MainWindow::Resize()
{
    switch (m_Plane)
    {
    case XYPLANE:
        m_XSize = m_XDim;
        m_YSize = m_YDim;
        break;
    case XZPLANE:
        m_XSize = m_XDim;
        m_YSize = m_ZDim;
        break;
    case YZPLANE:
        m_XSize = m_YDim;
        m_YSize = m_ZDim;
        break;
    }
}

void MainWindow::CreateBitmap()
{

    //m_YSize = m_Header.ysize;
    //m_XSize = m_Header.xsize;
    //m_ZSize = m_Header.zsize;

    int XRoundupSize;
        if (m_XSize % 4)
            XRoundupSize = m_XSize + 4 - (m_XSize % 4);
        else
            XRoundupSize = m_XSize;
        if (m_BitmapArray != NULL)
            delete [] m_BitmapArray;
        if (m_BitmapBuffer != NULL)
            delete [] m_BitmapBuffer;
        m_BitmapBuffer = new unsigned char [m_YSize*XRoundupSize];
        m_BitmapArray = new unsigned char * [m_YSize];
        m_BitmapBufferSize = m_YSize*XRoundupSize;
        for (unsigned int a=0; a<m_YSize; ++a)
            m_BitmapArray[a] = &m_BitmapBuffer[a*XRoundupSize];
}

void MainWindow::UpdateSlice()
{
    unsigned int x,y;
    unsigned char ***VIm, *Pix, **Slice, *Bmp;
    //unsigned int m_YSize,m_XSize,m_ZSize;

    VIm = GetIm();
    switch(m_Plane)
    {
    case XYPLANE:
        for (y=0; y<m_YSize; ++y)
        {
            Pix = VIm[m_ZSlice][y];
            Bmp = m_BitmapArray[y];
            for (x=0; x<m_XSize; ++x)
                *Bmp++ = Pix[x];
        }
        break;
    case XZPLANE:
        for (y=0; y<m_YSize; ++y)
        {
            Bmp = m_BitmapArray[y];
            Pix = VIm[y][m_YSlice];
            for (x=0; x<m_XSize; ++x)
                *Bmp++ = Pix[x];
        }
        break;
    case YZPLANE:
        for (y=0; y<m_YSize; ++y)
        {
            Bmp = m_BitmapArray[y];
            Slice = VIm[y];
            for (x=0; x<m_XSize; ++x)
                *Bmp++ = Slice[x][m_XSlice];
        }
        break;
    }
    m_BMPSlice = m_CurrentSlice;
    QImage  qISlice(m_BitmapBuffer,m_XSize,m_YSize,m_XSize,QImage::Format_Indexed8);
    child->showSlice(qISlice);
}
