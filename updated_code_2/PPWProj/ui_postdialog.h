/********************************************************************************
** Form generated from reading UI file 'postdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTDIALOG_H
#define UI_POSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_PostDialog
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *PostDialog)
    {
        if (PostDialog->objectName().isEmpty())
            PostDialog->setObjectName(QString::fromUtf8("PostDialog"));
        PostDialog->resize(400, 183);
        textEdit = new QTextEdit(PostDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 30, 360, 30));
        pushButton = new QPushButton(PostDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 89, 25));
        textEdit_2 = new QTextEdit(PostDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(20, 80, 360, 30));
        QWidget::setTabOrder(textEdit, textEdit_2);
        QWidget::setTabOrder(textEdit_2, pushButton);

        retranslateUi(PostDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), PostDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PostDialog);
    } // setupUi

    void retranslateUi(QDialog *PostDialog)
    {
        PostDialog->setWindowTitle(QCoreApplication::translate("PostDialog", "PostDialog", nullptr));
        pushButton->setText(QCoreApplication::translate("PostDialog", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostDialog: public Ui_PostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTDIALOG_H
