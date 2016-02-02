#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TomHeader.h"
#include "qtomviewview.h"

class QTomViewView;
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
    QTomViewView *child;// = createMdiChild();


public:

    struct thead m_Header;
    bool m_Empty;
    bool m_New;

    uint16_t xsize,ysize,zsize,num_samples,num_proj,num_blocks,num_slices,num_frames;
    float scale,voltage,current,pixel_size,exposure;
    uint32_t theta;
    QString time,duration,owner,user,specimen,scan,comment;
    QByteArray tomData;



protected:

    void StartMessage(void);
    QString m_FilePath;
    QString m_FileName;

public:
    int m_MinX;
    int m_MaxX;
    int m_MinY;
    int m_MaxY;
    int m_MinZ;
    int m_MaxZ;
    bool m_CropTags;
    void Texit(QString Message);
    void Alert(QString Message, QString Title);

private slots:
    QTomViewView *createMdiChild();
    void on_actionInformation_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_action25_triggered();
    void on_action50_triggered();
    void on_action100_triggered();
    void on_action200_triggered();
    void on_action300_triggered();
};

#endif // MAINWINDOW_H
