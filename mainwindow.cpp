#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "infodialog.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_ImRow(NULL)
  , m_FilePath((""))
  , m_FileName((""))
  , m_MinX(0)
  , m_MaxX(0)
  , m_MinY(0)
  , m_MaxY(0)
  , m_MinZ(0)
  , m_MaxZ(0)
  , m_CropTags(false)
{
    ui->setupUi(this);
    m_Empty = true;
    m_Im = NULL;
    m_ImRow = NULL;
    m_ImBuffer = NULL;
    m_Header.xsize = 0;
    m_New = false;


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

    long yzArea = (long)m_Header.ysize*m_Header.zsize;
    long xyArea = (long)m_Header.xsize*m_Header.ysize;

    if (m_Im)
    {
        delete m_Im;
        delete m_ImRow;
        for (a=0; a<m_Header.zsize; ++a)
            delete m_ImBuffer[a];
        delete m_ImBuffer;
    }
    if ((m_ImBuffer = new unsigned char*[m_Header.zsize]) == NULL)
        Texit("Insufficient Memory");
    for (a=0; a<m_Header.zsize; ++a)
    {
        if ((m_ImBuffer[a] = new unsigned char[xyArea]) == NULL)
            Texit("Insufficient Memory");
    }
    if ((m_ImRow = new unsigned char*[yzArea]) == NULL)
        Texit("Insufficient Memory");
    if ((m_Im = new unsigned char**[m_Header.zsize]) == NULL)
        Texit("Insufficient Memory");

    for (a=0; a< m_Header.zsize; ++a)
    {
        for (b=0; b<m_Header.ysize; ++b)
            m_ImRow[a*m_Header.ysize+b] = &(m_ImBuffer[a][b*m_Header.xsize]);
        m_Im[a] = &m_ImRow[a*m_Header.ysize];
    }



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

unsigned char*** MainWindow::GetIm()
{
    return m_Im;
}


void MainWindow::on_actionInformation_triggered()
{
    InfoDialog *id = new InfoDialog;
    id->pMw = getpointer();
    id->show();
}



void MainWindow::on_actionOpen_triggered()
{
    m_FileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.tom)"));
    QFile TOMFILE(m_FileName);
    if (!TOMFILE.open(QIODevice::ReadOnly)) Alert("Cannot open file","File open error.");
    qint64 bytes = TOMFILE.read((char*) &m_Header, sizeof(m_Header));
    if (bytes != sizeof(m_Header)) Texit("Cannot read header");

//    //ints
//    xsize = m_Header.xsize;
//    ysize = m_Header.ysize;
//    zsize = m_Header.zsize;
//    num_samples = m_Header.num_samples;
//    num_proj = m_Header.num_samples;
//    num_blocks = m_Header.num_blocks;
//    num_slices = m_Header.num_slices;
//    num_frames = m_Header.num_frames;

//    //floats
//    scale = m_Header.scale;
//    voltage = m_Header.voltage;
//    current = m_Header.current;
//    pixel_size = m_Header.pixel_size;
//    exposure = m_Header.exposure;
//    theta = m_Header.theta;
//    time = m_Header.time;

//    //Qstrings
//    duration=m_Header.duration;
//    owner=m_Header.owner;
//    user=m_Header.user;
//    specimen=m_Header.specimen;
//    scan=m_Header.scan;
//    comment=m_Header.comment;

}
