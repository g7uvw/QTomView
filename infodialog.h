#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class InfoDialog;
}


class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(const thead &header,QWidget *parent = 0);
    ~InfoDialog();
private slots:


private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
