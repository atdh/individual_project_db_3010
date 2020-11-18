#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogfactory.h"
#include "mydialog.h"
#include "postdialog.h"
#include <QtDebug>
#include <QFileDialog>
#include <filesystem>
#include <vector>

DatabaseBST* MyDialog::db = new DatabaseBST();

std::vector<int> get_inds(std::string file_name) {
    std::vector<int> inds;

    for (int i = 0; i < (int)file_name.length(); i++) {
        char c = file_name[i];
        if (c == (char)'/') {
            inds.push_back(i);
        }
    }

    return inds;
}

std::string MainWindow::GetFilePath(std::string file_name)
{
    QString fullpath = QCoreApplication::applicationDirPath();
    std::string str_file_path = fullpath.toLocal8Bit().constData();

    std::vector<int> inds = get_inds(str_file_path);

    if (inds.size() > 2) {
        str_file_path = str_file_path.substr(0, inds[inds.size()-2]);
    }

    str_file_path += "/PPWProj/" + file_name;
    qDebug() << QString::fromStdString(str_file_path);
    return str_file_path;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , key_vec(32, '$')
    , value_vec(32, '$')
    , ui(new Ui::MainWindow)
{

    std::string storage_fp = GetFilePath("storage.txt");
    std::string data_fp = GetFilePath("data.txt");

    MyDialog::db->set_file_path("storage.txt", storage_fp);
    MyDialog::db->set_file_path("data.txt", data_fp);

    FILE *fp = fopen(MyDialog::db->get_file_path("storage.txt").c_str(), "r");

    Node *tmp_root = MyDialog::db->get_root();

    QFile fi(QString::fromStdString(MyDialog::db->get_file_path("storage.txt")));

    int size_storage = fi.size();

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    REST_TYPE type = GET;
    QDialog* gd = DialogFactory::Create(type);

    gd->setModal(true);
    gd->exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    REST_TYPE type = POST;
    QDialog* pd = DialogFactory::Create(type);
    connect(pd, SIGNAL(AddKeyVal(std::string, std::string, Response)), this, SLOT(Handle_AddKeyVal(std::string, std::string, Response)));

    pd->setModal(true);
    pd->exec();
}

void MainWindow::Handle_AddKeyVal(std::string key, std::string value, Response res)
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

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{

}
