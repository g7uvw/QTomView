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


public:
    unsigned char*** GetIm();


protected:
    void AllocateMemory();
    unsigned char*** m_Im;
    //void closeEvent(QCloseEvent *event);
    void StartMessage(void);


private:
    unsigned char** m_ImBuffer;
public:
    //afx_msg void OnUpdateViewContrast(CCmdUI *pCmdUI);
protected:
    unsigned char** m_ImRow;
public:

protected:
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
    //afx_msg void OnExportImagej();
    //afx_msg void OnCopymetadata();
    //afx_msg void OnUpdateCopymetadata(CCmdUI *pCmdUI);
    void Texit(QString Message);
    void Alert(QString Message, QString Title);

private slots:
    void on_actionInformation_triggered();
    void on_actionOpen_triggered();
    QTomViewView *createMdiChild();
    void on_actionExit_triggered();
};

#endif // MAINWINDOW_H
