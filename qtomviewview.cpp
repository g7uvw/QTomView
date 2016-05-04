#include <QtWidgets>
#include "qtomviewview.h"

QTomViewView::QTomViewView(QWidget *parent)
    : QWidget(parent)
{
    setAttribute (Qt::WA_StaticContents);

    //setWindowTitle("New");
    //setAttribute(Qt::WA_DeleteOnClose);
    //isUntitled = true;
    //view = new QGraphicsView;
    //view->setMouseTracking(true);
    //scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);

    //    scene->addText("Hello, world!");
    //    for (int i=0;i<40;i++)
    //    {   //qsrand(time(NULL));
    //        int x = qrand() % ((400))+1;
    //        int y = qrand() % (400)+1;
    //        int w = qrand() % ((x/y+1))+1;
    //        int h = qrand() % ((y/x+1))+1;
    //        scene->addEllipse(x,y,w,h);
    //    }
    //    scene->addEllipse(100,100,30,30);
    //    view->setScene(scene);
    //    setCentralWidget(view);
}

void QTomViewView::wipe()
{
    displayedslice.fill(qRgb (255,255,255));
    update();
}

void QTomViewView::showSlice(QImage &slice)
{
    displayedslice = slice;
    update();
//    QSize slicesize = slice.size();
//    scene->clear();
//    QPixmap currentslice(QPixmap::fromImage(slice));
//    scene->addPixmap(currentslice);
//    scene->update();

//    QSize viewsize = view->size();
//    view->adjustSize();
//    viewsize = view->size();
//    view->update();

}





void QTomViewView::zoom(int zoomlevelpercent)
{
    //view->scale(view->x()*zoomlevelpercent,view->y()*zoomlevelpercent);
    //view->update();
}

void QTomViewView::mousePressEvent(QMouseEvent *event)

{
    //    if (event->button() == Qt::LeftButton) {
    //        lastPoint = event->pos();
    //        scribbling = true;
    //    }
}

void QTomViewView::mouseMoveEvent(QMouseEvent *event)
{
    // TODO put mouse move code here

    // if ((event->buttons() & Qt::LeftButton) && scribbling)
    //     drawLineTo(event->pos());
}

void QTomViewView::mouseReleaseEvent(QMouseEvent *event)
{
    //    if (event->button() == Qt::LeftButton && scribbling) {
    //        drawLineTo(event->pos());
    //        scribbling = false;
    //    }
}

void QTomViewView::paintEvent (QPaintEvent *event)
{
    QPainter painter(this);
    QRect drawRect(0,0,displayedslice.width (),displayedslice.height ());
    painter.drawImage(drawRect, displayedslice, drawRect);
}

void QTomViewView::dumpBMPs ()
{

}
