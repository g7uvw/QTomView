#ifndef QTOMVIEWVIEW_H
#define QTOMVIEWVIEW_H
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWidget>

class QTomViewView : public QWidget
{
    Q_OBJECT
public:
    QTomViewView(QWidget *parent = 0);

    bool loadFile(const QString &fileName);
    void showSlice(QImage &slice);
    void zoom(int zoomlevelpercent);



public slots:
    void wipe();
    void dumpBMPs();


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QImage displayedslice;
    //void setCurrentFile(const QString &fileName);

    //QGraphicsView *view;
    //QGraphicsScene *scene;

    //QString curFile;
    //bool isUntitled;

};

#endif // QTOMVIEWVIEW_H

