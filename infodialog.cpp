#include "infodialog.h"
#include "ui_infodialog.h"
//#include "TomHeader.h"
//#include "mainwindow.h"


InfoDialog::InfoDialog(const thead &header,QWidget *parent) : QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
    ui->label_belong->setText(ui->label_belong->text()+header.owner);
    ui->label_run->setText(ui->label_run->text()+header.user);
    ui->label_date->setText(ui->label_date->text()+header.scan);
    QString size = "Size: ";
    size.append(QString::number(header.xsize));
    size.append("x");
    size.append(QString::number(header.ysize));
    size.append("x");
    size.append(QString::number(header.zsize));
    ui->label_size->setText(size);
    ui->label_voxelsize->setText(ui->label_voxelsize->text()+QString::number(header.pixel_size));
    ui->label_scale->setText(ui->label_scale->text()+QString::number(header.scale));
    ui->label_voltage->setText(ui->label_voltage->text()+QString::number(header.voltage));
    ui->label_current->setText(ui->label_current->text()+QString::number(header.current));
    ui->label_projections->setText(ui->label_projections->text()+QString::number(header.num_proj));

    unsigned int wibble = pMw->m_Header.xsize;
    ui->label_belong->setText(QString(wibble));
    //ui->label_date->setText(pMw->m_Header.time);
    //ui->lable_belong->setText(mw->m_Header.owner);

}

InfoDialog::~InfoDialog()
{
    delete ui;
}


