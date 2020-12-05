/********************************************************************************
** Form generated from reading UI file 'getdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIALOG_H
#define UI_GETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GetDialog
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *GetDialog)
    {
        if (GetDialog->objectName().isEmpty())
            GetDialog->setObjectName(QStringLiteral("GetDialog"));
        GetDialog->resize(400, 124);
        textEdit = new QTextEdit(GetDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 360, 30));
        pushButton = new QPushButton(GetDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 80, 89, 25));

        retranslateUi(GetDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), GetDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(GetDialog);
    } // setupUi

    void retranslateUi(QDialog *GetDialog)
    {
        GetDialog->setWindowTitle(QApplication::translate("GetDialog", "GetDialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GetDialog", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GetDialog: public Ui_GetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIALOG_H
