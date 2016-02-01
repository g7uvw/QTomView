
#include "qtomviewview.h"


QTomViewView::QTomViewView()
{
    setWindowTitle("New");
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;


    view = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);

    scene->addText("Hello, world!");
    for (int i=0;i<40;i++)
    {   //qsrand(time(NULL));
        int x = qrand() % ((400))+1;
        int y = qrand() % (400)+1;
        int w = qrand() % ((x/y+1))+1;
        int h = qrand() % ((y/x+1))+1;
        scene->addEllipse(x,y,w,h);
    }
    scene->addEllipse(100,100,30,30);
    view->setScene(scene);
    setCentralWidget(view);
}

void QTomViewView::wipe()
{
    //QMessageBox msgBox;
    //msgBox.setText("Click OK to crash!");
    //msgBox.exec();
    scene->clear();


}

void QTomViewView::showSlice(QImage &slice)
{
    scene->clear();
    scene->addText("Image here!");
    QPixmap item(QPixmap::fromImage(slice));
    //QPixmap test(200,200);
    scene->addPixmap(item);
    //scene->addPixmap(test);
    scene->update();
    view->update();
}


bool QTomViewView::loadFile(const QString &fileName)
{
    QFile file(fileName);
    setCurrentFile(fileName);
    return true;
}

void QTomViewView::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    setWindowModified(false);
}

QString QTomViewView::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


