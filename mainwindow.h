#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TomHeader.h"
#include "qtomv_view.h"
#include "tomslicer.h"

class QTomV_View;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MainWindow* getpointer() {return this;}

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    QSignalMapper *windowMapper;
    QTomV_View *view_area;
    QLabel *statusPositions;
    QLabel *statusPosLAC;
    QLabel *statusPosToOrigin;
    QLabel *statusPosAngle;
    QLabel *statusCubeLAC;
    QProgressBar *statusProgressBar;
    
public:

    struct thead m_Header;
    bool m_Empty;
    bool m_New;

    uint16_t xsize,ysize,zsize,num_samples,num_proj,num_blocks,num_slices,num_frames;
    float scale,voltage,current,pixel_size,exposure;
    uint32_t theta;
    QString time,duration,owner,user,specimen,scan,comment;
    //QByteArray tomData;
    //QVector<QRgb> colorTable;
    //TOMSlicer* slicer;
    //std::vector<uint8_t> volume;


protected:
    void AllocateMemory(void);
    void StartMessage(void);
    void CreateDefaultLookup(void);
    void UpdateSlice(void);
    void CreateBitmap();
    unsigned char *** GetIm();
    QString m_FilePath;
    QString m_FileName;

public:
    int m_MinX;
    int m_MaxX;
    int m_MinY;
    int m_MaxY;
    int m_MinZ;
    int m_MaxZ;
    unsigned int m_CurrentSlice, m_XSlice, m_YSlice, m_ZSlice;
    unsigned int m_Plane;
    //unsigned int m_XSlice, m_YSlice, m_ZSlice, m_BMPSlice, m_BMPPlane,m_BitmapBufferSize;
    bool m_CropTags;
    void Texit(QString Message);
    void Alert(QString Message, QString Title);

private slots:
    QTomV_View *createMdiChild();
    void on_actionInformation_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionDown_Slice_triggered();
    void on_actionUpSlice_triggered();
    void on_actionXY_Slice_triggered();
    void on_actionYZ_Slice_triggered();
    void on_actionXZ_Slice_triggered();
    void wheelEvent(QWheelEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    void on_action25_triggered();
    void on_action50_triggered();
    void on_action100_triggered();
    void on_action200_triggered();
    void on_action300_triggered();
};

#endif // MAINWINDOW_H
