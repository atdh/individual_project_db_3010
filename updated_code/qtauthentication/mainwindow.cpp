#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>


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

void MainWindow::readFile()
{
    QFile fileName("authentication.txt");
    if(!fileName.exists()){
        qDebug()<<"file doesnt exist";
    }

    /*
    std::ifstream fileName;
    //reading do in
    fileName.open("authentication.txt", std::ios::in);
    std::string line = "";
    std::string username = "";
    std::string password = "";
    //file pointer
    while (fileName >> username >> password)
    {
        //std::cout << username << "," << password << std::endl;
        table.insert(std::pair<std::string, std::string>(username, password));
    }
    fileName.close();*/
}

void MainWindow::on_pushButton_login_clicked()
{
    QString userAttempt = ui->lineEdit_username->text();
    QString passwordAttempt = ui->lineEdit_2_password->text();

    readFile();

    if(table[userAttempt] == passwordAttempt){
        accessGranted = true;
        QMessageBox::information(this,"Login","Authenticated successfully");
        hide();
        secDialog = new Dialog(this);
        secDialog->show();
    }
    else{
        QMessageBox::warning(this,"login", "You have not made an account or incorrect password");
    }

}

void MainWindow::on_pushButton_signup_clicked()
{
    QMessageBox::information(this, "signup", "sign up succesful");
}
