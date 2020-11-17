#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_2_password->text();

    if(username == "test" && password == "test"){
        QMessageBox::information(this,"Login","password is correct");
        hide();
        secDialog = new Dialog(this);
        secDialog->show();
    }
    else{
        QMessageBox::warning(this,"login", "incorrect");
    }

}
