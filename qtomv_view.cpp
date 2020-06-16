
#include "qtomv_view.h"


QTomV_View::QTomV_View()
{
    setWindowTitle("New");
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
    view = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    view->setScene(scene);
    setCentralWidget(view);
    slicer = TOMSlicer::getInstance();
}

void QTomV_View::wipe()
{
    scene->clear();
}

void QTomV_View::ReceiveHeader(thead header)
{
    m_Header = header;
}

void QTomV_View::showSlice(QImage &slice)
{
    scene->clear();
    QPixmap currentslice(QPixmap::fromImage(slice));
    scene->addPixmap(currentslice);
    scene->update();
    view->update();
}


QString QTomV_View::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


void QTomV_View::zoom(int zoomlevelpercent)
{
    view->scale(view->x()*zoomlevelpercent,view->y()*zoomlevelpercent);
    view->update();
}

void QTomV_View::CreateDefaultLookup()
{
    QVector<QRgb> colorTable;
    for (int i = 0; i < 256; i++)
        colorTable.push_back(QColor(i, i, i).rgb());
}

void QTomV_View::UpdateSlice(unsigned int a)
{
    m_Plane = a;
    CreateDefaultLookup();
    switch (m_Plane)
    {
    case YZPLANE:{
//      const std::vector<uint8_t>& TOMSlicer::YZSlice(const std::vector<uint8_t>& vol, size_t Xoffset, size_t xsize, size_t ysize, size_t zsize)
        const std::vector<uint8_t>&YZ = slicer->YZSlice(volume, m_XSlice, m_Header.xsize, m_Header.ysize, m_Header.zsize);
        QImage  YZSlice(YZ.data(),m_Header.ysize,m_Header.zsize,m_Header.ysize,QImage::Format_Indexed8);
        YZSlice.setColorTable(colorTable);
        resize(YZSlice.width(),YZSlice.height());
        showSlice(YZSlice);
        break;
        }

    case XZPLANE:{
      //const std::vector<uint8_t>& TOMSlicer::XZSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Yoffset, size_t zsize)
        const std::vector<uint8_t>&XZ = slicer->XZSlice(volume, m_Header.xsize, m_Header.ysize, m_YSlice, m_Header.zsize);
        QImage  XZSlice(XZ.data(),m_Header.xsize,m_Header.zsize,m_Header.xsize,QImage::Format_Indexed8);
        XZSlice.setColorTable(colorTable);

        resize(XZSlice.width(),XZSlice.height());
        showSlice(XZSlice);
        break;
        }

    default:
    case XYPLANE:{
        const std::vector<uint8_t>&XY = slicer->XYSlice(volume, m_Header.xsize, m_Header.ysize, m_ZSlice);
        QImage  XYSlice(XY.data(),m_Header.xsize,m_Header.ysize,m_Header.xsize,QImage::Format_Indexed8);
        XYSlice.setColorTable(colorTable);

        resize(XYSlice.width(),XYSlice.height());
        showSlice(XYSlice);
        break;
        }
    }

}
