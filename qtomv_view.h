#ifndef QTOMVIEWVIEW_H
#define QTOMVIEWVIEW_H
#include <QPainter>
#include <QtWidgets>
#include "mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include "TomHeader.h"
#include "tomslicer.h"
///#include "TomView.h"

const short XYPLANE = 1;
const short XZPLANE = 2;
const short YZPLANE = 3;

class QTomV_View : public QMainWindow
{
    Q_OBJECT
public:
    QTomV_View();
    bool loadFile(const QString &fileName);
    QString userFriendlyCurrentFile();
    QString currentFile() { return curFile; }

    std::vector<uint8_t> volume;

    void zoom(int zoomlevelpercent);
    void ReceiveHeader(thead header);
   
    
    struct s_Slice
    {
        uint8_t Plane  = XYPLANE;
        size_t  XSlice = 0;
        size_t  YSlice = 0;
        size_t  ZSlice = 0;
        
    };
     
    void UpdateSlice(s_Slice Slice);

protected:
    QByteArray tomData;
    QVector<QRgb> colorTable;
    struct thead m_Header;
    TOMSlicer* slicer;
 //void QTomV_View::wheelEvent(QWheelEvent* event);

    void CreateDefaultLookup(void);
    void wipe();
    void showSlice(QImage &slice);
    unsigned int m_Plane, m_CurrentSlice, m_XSlice, m_YSlice, m_ZSlice;

private:
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QGraphicsView *view;
    QGraphicsScene *scene;

    QString curFile;
    bool isUntitled;

};

#endif // QTOMVIEWVIEW_H

