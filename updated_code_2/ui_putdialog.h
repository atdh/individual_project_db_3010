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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_PutDialog
{
public:
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *PutDialog)
    {
        if (PutDialog->objectName().isEmpty())
            PutDialog->setObjectName(QStringLiteral("PutDialog"));
        PutDialog->resize(400, 183);
        textEdit = new QTextEdit(PutDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 360, 30));
        textEdit_2 = new QTextEdit(PutDialog);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 80, 360, 30));
        pushButton = new QPushButton(PutDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 89, 25));

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
