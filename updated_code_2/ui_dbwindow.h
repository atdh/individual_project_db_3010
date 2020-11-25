/********************************************************************************
** Form generated from reading UI file 'dbwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBWINDOW_H
#define UI_DBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <clickablelabel.h>

QT_BEGIN_NAMESPACE

class Ui_DBWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget;
    QLabel *response_stat_title;
    QLabel *response_stat;
    QLabel *response_message_title;
    QLabel *response_message_1;
    QTableWidget *tableWidget_2;
    QLabel *response_message_2;
    ClickableLabel *home_label;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DBWindow)
    {
        if (DBWindow->objectName().isEmpty())
            DBWindow->setObjectName(QStringLiteral("DBWindow"));
        DBWindow->resize(810, 505);
        centralwidget = new QWidget(DBWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 40, 181, 111));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 40, 181, 111));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 40, 181, 111));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(600, 40, 181, 111));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(570, 180, 220, 271));
        tableWidget->setRowCount(0);
        response_stat_title = new QLabel(centralwidget);
        response_stat_title->setObjectName(QStringLiteral("response_stat_title"));
        response_stat_title->setGeometry(QRect(20, 180, 121, 17));
        response_stat = new QLabel(centralwidget);
        response_stat->setObjectName(QStringLiteral("response_stat"));
        response_stat->setGeometry(QRect(20, 200, 111, 21));
        response_message_title = new QLabel(centralwidget);
        response_message_title->setObjectName(QStringLiteral("response_message_title"));
        response_message_title->setGeometry(QRect(20, 240, 141, 17));
        response_message_1 = new QLabel(centralwidget);
        response_message_1->setObjectName(QStringLiteral("response_message_1"));
        response_message_1->setGeometry(QRect(20, 260, 291, 21));
        tableWidget_2 = new QTableWidget(centralwidget);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setGeometry(QRect(330, 180, 221, 271));
        tableWidget_2->setRowCount(0);
        response_message_2 = new QLabel(centralwidget);
        response_message_2->setObjectName(QStringLiteral("response_message_2"));
        response_message_2->setGeometry(QRect(20, 280, 291, 21));
        home_label = new ClickableLabel(centralwidget);
        home_label->setObjectName(QStringLiteral("home_label"));
        home_label->setGeometry(QRect(763, 4, 31, 31));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 410, 89, 25));
        DBWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DBWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 22));
        DBWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DBWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DBWindow->setStatusBar(statusbar);

        retranslateUi(DBWindow);

        QMetaObject::connectSlotsByName(DBWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DBWindow)
    {
        DBWindow->setWindowTitle(QApplication::translate("DBWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DBWindow", "GET", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("DBWindow", "POST", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("DBWindow", "PUT", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("DBWindow", "DELETE", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DBWindow", "Key", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DBWindow", "Value", Q_NULLPTR));
        response_stat_title->setText(QApplication::translate("DBWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Response Status:</span></p></body></html>", Q_NULLPTR));
        response_stat->setText(QString());
        response_message_title->setText(QApplication::translate("DBWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Response Message:</span></p></body></html>", Q_NULLPTR));
        response_message_1->setText(QString());
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("DBWindow", "User", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("DBWindow", "Password", Q_NULLPTR));
        response_message_2->setText(QString());
        home_label->setText(QApplication::translate("DBWindow", "<html><head/><body><p><img src=\":/home.png\"/></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("DBWindow", "Delete User", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBWindow: public Ui_DBWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBWINDOW_H
