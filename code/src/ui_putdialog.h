/********************************************************************************
** Form generated from reading UI file 'putdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUTDIALOG_H
#define UI_PUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PutDialog
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *PutDialog)
    {
        if (PutDialog->objectName().isEmpty())
            PutDialog->setObjectName(QStringLiteral("PutDialog"));
        PutDialog->resize(400, 183);
        pushButton = new QPushButton(PutDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 89, 25));
        lineEdit = new QLineEdit(PutDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 360, 30));
        lineEdit_2 = new QLineEdit(PutDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 80, 360, 30));

        retranslateUi(PutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), PutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PutDialog);
    } // setupUi

    void retranslateUi(QDialog *PutDialog)
    {
        PutDialog->setWindowTitle(QApplication::translate("PutDialog", "PutDialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PutDialog", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PutDialog: public Ui_PutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUTDIALOG_H
