#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TomHeader.h"

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

public:

    struct thead m_Header;
    bool m_Empty;
    bool m_New;

    uint16_t xsize,ysize,zsize,num_samples,num_proj,num_blocks,num_slices,num_frames;
    float scale,voltage,current,pixel_size,exposure;
    uint32_t theta;
    QString time,duration,owner,user,specimen,scan,comment;


public:
    unsigned char*** GetIm();


protected:
    void AllocateMemory();
    unsigned char*** m_Im;

    // afx_msg void OnUpdateViewSlice(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateInfobutton(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateFilePrint(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateViewZoom(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateExportBitmap(CCmdUI* pCmdUI);
    // afx_msg void OnUpdateContrastbutton(CCmdUI* pCmdUI);
    //}}AFX_MSG
    // DECLARE_MESSAGE_MAP()
private:
    unsigned char** m_ImBuffer;
public:
    //afx_msg void OnUpdateViewContrast(CCmdUI *pCmdUI);
protected:
    unsigned char** m_ImRow;
public:
    //afx_msg void OnExportCrop();
    //afx_msg void OnExportPvlfordrishti();
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
};

#endif // MAINWINDOW_H
