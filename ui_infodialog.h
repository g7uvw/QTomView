/********************************************************************************
** Form generated from reading UI file 'infodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
//#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_belong;
    QLabel *label_run;
    QLabel *label_date;
    QLabel *label_size;
    QLabel *label_voxelsize;
    QLabel *label_scale;
    QLabel *label_voltage;
    QLabel *label_current;
    QLabel *label_projections;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InfoDialog)
    {
        if (InfoDialog->objectName().isEmpty())
            InfoDialog->setObjectName(QStringLiteral("InfoDialog"));
        InfoDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(InfoDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_belong = new QLabel(InfoDialog);
        label_belong->setObjectName(QStringLiteral("label_belong"));

        verticalLayout->addWidget(label_belong);

        label_run = new QLabel(InfoDialog);
        label_run->setObjectName(QStringLiteral("label_run"));

        verticalLayout->addWidget(label_run);

        label_date = new QLabel(InfoDialog);
        label_date->setObjectName(QStringLiteral("label_date"));

        verticalLayout->addWidget(label_date);

        label_size = new QLabel(InfoDialog);
        label_size->setObjectName(QStringLiteral("label_size"));

        verticalLayout->addWidget(label_size);

        label_voxelsize = new QLabel(InfoDialog);
        label_voxelsize->setObjectName(QStringLiteral("label_voxelsize"));

        verticalLayout->addWidget(label_voxelsize);

        label_scale = new QLabel(InfoDialog);
        label_scale->setObjectName(QStringLiteral("label_scale"));

        verticalLayout->addWidget(label_scale);

        label_voltage = new QLabel(InfoDialog);
        label_voltage->setObjectName(QStringLiteral("label_voltage"));

        verticalLayout->addWidget(label_voltage);

        label_current = new QLabel(InfoDialog);
        label_current->setObjectName(QStringLiteral("label_current"));

        verticalLayout->addWidget(label_current);

        label_projections = new QLabel(InfoDialog);
        label_projections->setObjectName(QStringLiteral("label_projections"));

        verticalLayout->addWidget(label_projections);

        buttonBox = new QDialogButtonBox(InfoDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InfoDialog);
    } // setupUi

    void retranslateUi(QDialog *InfoDialog)
    {
        InfoDialog->setWindowTitle(QApplication::translate("InfoDialog", "Dialog", Q_NULLPTR));
        label_belong->setText(QApplication::translate("InfoDialog", "Belonging to: ", Q_NULLPTR));
        label_run->setText(QApplication::translate("InfoDialog", "Run by: ", Q_NULLPTR));
        label_date->setText(QApplication::translate("InfoDialog", "Date / Time :", Q_NULLPTR));
        label_size->setText(QApplication::translate("InfoDialog", "Size: ", Q_NULLPTR));
        label_voxelsize->setText(QApplication::translate("InfoDialog", "Voxel Size: ", Q_NULLPTR));
        label_scale->setText(QApplication::translate("InfoDialog", "Scale: ", Q_NULLPTR));
        label_voltage->setText(QApplication::translate("InfoDialog", "Voltage: ", Q_NULLPTR));
        label_current->setText(QApplication::translate("InfoDialog", "Current: ", Q_NULLPTR));
        label_projections->setText(QApplication::translate("InfoDialog", "Number of projections: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoDialog: public Ui_InfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
