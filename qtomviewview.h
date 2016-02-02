#ifndef QTOMVIEWVIEW_H
#define QTOMVIEWVIEW_H
#include <QPainter>
#include <QtWidgets>
#include "mainwindow.h"
#include <QtCore>
#include <QtWidgets>

class QTomViewView : public QMainWindow
{
    Q_OBJECT
public:
    QTomViewView();
    bool loadFile(const QString &fileName);
    QString userFriendlyCurrentFile();
    QString currentFile() { return curFile; }
    //static QByteArray tomData;
    static QImage slice;
    void wipe();
    void showSlice(QImage &slice);
    void zoom(int zoomlevelpercent);

protected:
    //void closeEvent(QCloseEvent *event);

private:
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QGraphicsView *view;
    QGraphicsScene *scene;

    QString curFile;
    bool isUntitled;
   // QGraphicsScene *view;
   // QPixmap slice;

};

#endif // QTOMVIEWVIEW_H

