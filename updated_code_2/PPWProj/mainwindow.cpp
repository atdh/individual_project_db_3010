#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogfactory.h"
#include "mydialog.h"
#include "postdialog.h"
#include <QtDebug>
#include <QFileDialog>
#include <filesystem>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

// since the database is a static variable, we instantiate it here
// made the database static so that it can be accessed more easily (through the class itself)
DatabaseBST* MyDialog::db = new DatabaseBST();

// we need to use the QCoreApplication::applicationDirPath() method in order to help us
// get the full path of where the data and storage files are
std::string MainWindow::GetFilePath(std::string file_name)
{
    std::string str_file_path = QDir::currentPath().toLocal8Bit().constData();
    str_file_path += "/" + file_name;
    qDebug() << QString::fromStdString(str_file_path);
    return str_file_path;
}

// this is the main dialog upon starting up the application
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    std::string storage_fp = GetFilePath("storage.txt");
    std::string data_fp = GetFilePath("data.txt");

    MyDialog::db->set_file_path("storage.txt", storage_fp);
    MyDialog::db->set_file_path("data.txt", data_fp);

    FILE *fp = fopen(MyDialog::db->get_file_path("storage.txt").c_str(), "r");

    Node *tmp_root = MyDialog::db->get_root();

    // first, we check if there is any bytes in the storage file
    QFile fi(QString::fromStdString(MyDialog::db->get_file_path("storage.txt")));

    int size_storage = fi.size();

    // if there is information in the storage file, then we recreate the bst
    // using the information of the file
    // NOTE: the file contains the entries, with each entry representing
    // the hash value (16 bytes), the key (32 bytes), and value (32 bytes); each entry is
    // 16+32+32 = 80 bytes
    if (size_storage > 0)
    {
        std::cout << "Rebuilding the BST" << std::endl;
        MyDialog::db->Deserialize(tmp_root, fp);
        MyDialog::db->set_root(tmp_root);
    }

    std::string data_file = "data.txt";
    std::fstream streamer(data_file, std::ios::in | std::ios::out);

    ui->setupUi(this);
    ui->pushButton->setText("GET");
    ui->pushButton_2->setText("POST");
    ui->pushButton_3->setText("PUT");
    ui->pushButton_4->setText("DELETE");
}

// after we close the application, we need to make sure that we save the information
// in the data file into the storage file so that we can persistently save the
// entries upon future use
MainWindow::~MainWindow()
{
    std::ofstream myfile;
    myfile.open(MyDialog::db->get_file_path("data.txt").c_str(), std::ofstream::out | std::ofstream::trunc);
    myfile.close();

    FILE *fp = fopen(MyDialog::db->get_file_path("storage.txt").c_str(), "w");
    if (fp == NULL)
    {
        puts("Could not open the file");
    }

    std::cout << "Saving data to the storage file." << std::endl;
    MyDialog::db->Serialize(MyDialog::db->get_root(), fp);
    std::cout << "All done. Closing off." << std::endl;
    fclose(fp);

    delete ui;
}

// this launches the GET request dialog
void MainWindow::on_pushButton_clicked()
{
    REST_TYPE type = GET;
    QDialog* gd = DialogFactory::Create(type);

    gd->setModal(true);
    gd->exec();
}

// this launches the POST request dialog
void MainWindow::on_pushButton_2_clicked()
{
    REST_TYPE type = POST;
    QDialog* pd = DialogFactory::Create(type);
    connect(pd, SIGNAL(SendPostRes(std::string, std::string, Response)), this, SLOT(HandlePostRes(std::string, std::string, Response)));

    pd->setModal(true);
    pd->exec();
}

// this is the callback function of when the user submits the post request
void MainWindow::HandlePostRes(std::string key, std::string value, Response res)
{
    if (res.successful) {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message->setText(res.body_info);

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(key)));
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(value)));
    } else {
        ui->response_stat->setText("BAD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        ui->response_message->setText(res.body_info);
    }
}

// this launches the PUT request dialog
void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "In the put dialog";
    REST_TYPE type = PUT;
    QDialog* pd = DialogFactory::Create(type);
    pd->setModal(true);
    pd->exec();
}

// this launches the DELETE request dialog
void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "In the delete dialog";
    REST_TYPE type = DELETE;
    QDialog* dd = DialogFactory::Create(type);
    dd->setModal(true);
    dd->exec();
}
