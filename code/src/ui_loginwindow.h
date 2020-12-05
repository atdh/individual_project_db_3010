/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label_username;
    QLabel *label_password;
    QLineEdit *lineEdit_username;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_signup;
    QLabel *label_password_2;
    QLineEdit *lineEdit_password_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(810, 510);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 70, 300, 320));
        label_username = new QLabel(groupBox);
        label_username->setObjectName(QStringLiteral("label_username"));
        label_username->setGeometry(QRect(40, 40, 81, 17));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QStringLiteral("label_password"));
        label_password->setGeometry(QRect(40, 120, 67, 17));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(40, 70, 221, 25));
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setGeometry(QRect(90, 210, 120, 25));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(40, 150, 221, 25));
        pushButton_signup = new QPushButton(groupBox);
        pushButton_signup->setObjectName(QStringLiteral("pushButton_signup"));
        pushButton_signup->setGeometry(QRect(90, 260, 120, 25));
        label_password_2 = new QLabel(groupBox);
        label_password_2->setObjectName(QStringLiteral("label_password_2"));
        label_password_2->setGeometry(QRect(40, 180, 161, 17));
        lineEdit_password_2 = new QLineEdit(groupBox);
        lineEdit_password_2->setObjectName(QStringLiteral("lineEdit_password_2"));
        lineEdit_password_2->setGeometry(QRect(40, 210, 221, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 110, 231, 241));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 400, 221, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 420, 221, 17));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 22));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit_username, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, lineEdit_password_2);
        QWidget::setTabOrder(lineEdit_password_2, pushButton_login);
        QWidget::setTabOrder(pushButton_login, pushButton_signup);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_username->setText(QApplication::translate("LoginWindow", "Username", Q_NULLPTR));
        label_password->setText(QApplication::translate("LoginWindow", "Password", Q_NULLPTR));
        pushButton_login->setText(QApplication::translate("LoginWindow", "Login", Q_NULLPTR));
        pushButton_signup->setText(QApplication::translate("LoginWindow", "Sign up", Q_NULLPTR));
        label_password_2->setText(QApplication::translate("LoginWindow", "Re-enter Password", Q_NULLPTR));
        label->setText(QApplication::translate("LoginWindow", "<html><head/><body><p><img src=\":/person.png\"/></p></body></html>", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
