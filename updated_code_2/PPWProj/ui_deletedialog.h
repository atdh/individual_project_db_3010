/********************************************************************************
** Form generated from reading UI file 'deletedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEDIALOG_H
#define UI_DELETEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DeleteDialog
{
public:
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *DeleteDialog)
    {
        if (DeleteDialog->objectName().isEmpty())
            DeleteDialog->setObjectName(QString::fromUtf8("DeleteDialog"));
        DeleteDialog->resize(400, 124);
        pushButton = new QPushButton(DeleteDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 80, 89, 25));
        textEdit = new QTextEdit(DeleteDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 360, 30));

        retranslateUi(DeleteDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), DeleteDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(DeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteDialog)
    {
        DeleteDialog->setWindowTitle(QCoreApplication::translate("DeleteDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DeleteDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteDialog: public Ui_DeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEDIALOG_H
