
#include "qtomviewview.h"


QTomViewView::QTomViewView()
{
    setWindowTitle("New");
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;


    view = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    view->setScene(scene);
    setCentralWidget(view);
}

void QTomViewView::wipe()
{
    scene->clear();
}

void QTomViewView::showSlice(QImage &slice)
{
    scene->clear();
    QPixmap currentslice(QPixmap::fromImage(slice));
    scene->addPixmap(currentslice);
    scene->update();
    view->update();
}


QString QTomViewView::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


void QTomViewView::zoom(int zoomlevelpercent)
{
    view->scale(view->x()*zoomlevelpercent,view->y()*zoomlevelpercent);
    view->update();
}
