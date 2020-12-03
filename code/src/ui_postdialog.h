/********************************************************************************
** Form generated from reading UI file 'postdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTDIALOG_H
#define UI_POSTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PostDialog
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *PostDialog)
    {
        if (PostDialog->objectName().isEmpty())
            PostDialog->setObjectName(QStringLiteral("PostDialog"));
        PostDialog->resize(400, 183);
        pushButton = new QPushButton(PostDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 130, 89, 25));
        lineEdit = new QLineEdit(PostDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 360, 30));
        lineEdit_2 = new QLineEdit(PostDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 80, 360, 30));
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton);

        retranslateUi(PostDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), PostDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PostDialog);
    } // setupUi

    void retranslateUi(QDialog *PostDialog)
    {
        PostDialog->setWindowTitle(QApplication::translate("PostDialog", "PostDialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PostDialog", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PostDialog: public Ui_PostDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTDIALOG_H
