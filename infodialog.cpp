#include "infodialog.h"
#include "ui_infodialog.h"
//#include "TomHeader.h"
//#include "mainwindow.h"

InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    unsigned int wibble = pMw->m_Header.xsize;
    ui->lable_belong->setText(QString(wibble));
    //ui->label_date->setText(pMw->m_Header.time);
    //ui->lable_belong->setText(mw->m_Header.owner);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}


