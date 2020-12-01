#include "dbwindow.h"
#include "ui_dbwindow.h"
#include "dialogfactory.h"
#include "mydialog.h"
#include "postdialog.h"
#include <QtDebug>
#include <QFileDialog>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "loginwindow.h"
#include "deleteuserdialog.h"
#include "passworddialog.h"

// since the database is a static variable, we instantiate it here
// made the database static so that it can be accessed more easily (through the class itself)
DatabaseBST* MyDialog::db = new DatabaseBST();

// we need to use the QDir::currentPath() method in order to help us
// get the full path of where the data and storage files are
std::string DBWindow::GetFilePath(std::string file_name)
{
    std::string str_file_path = QDir::currentPath().toLocal8Bit().constData();
    str_file_path += "/" + file_name;
    qDebug() << QString::fromStdString(str_file_path);
    return str_file_path;
}

int GetFileSize(std::string file_name) {
    QFile fi(QString::fromStdString(MyDialog::db->get_file_path(file_name)));
    int file_size = fi.size();
    return file_size;
}

// giving this function another parameter to help indicate
// which table we are working with
int DBWindow::GetRowEntry(QString query, int table_num) {
    // return a list of all matching results
    // it looks at column 0 of the table
    // and looks at each row and creates a list of QModelIndex
    // object that match the given value
    QModelIndexList results;

    if (table_num == 1) {
        results = ui->tableWidget->model()->match(
                ui->tableWidget->model()->index(0, 0),
                Qt::DisplayRole,
                query, // the query in this case is the key that we want to find
                -1,
                Qt::MatchContains
       );
    } else if (table_num == 2) {
        results = ui->tableWidget_2->model()->match(
                ui->tableWidget->model()->index(0, 0),
                Qt::DisplayRole,
                query, // the query in this case is the name of the user we want to find
                -1,
                Qt::MatchContains
       );
    }

    if (results.length() > 0) {
        // results should only have one item, which is the QModelIndex
        // that contains the key
        return results[0].row();
    } else {
        std::cout << "Couldn't find the string" << std::endl;
        return -1;
    }
}

// this is the main dialog upon starting up the application
DBWindow::DBWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DBWindow)
    , lw_partner(0)
{
    ui->setupUi(this);
    std::string storage_fp = GetFilePath("storage.txt");
    std::string data_fp = GetFilePath("data.txt");

    MyDialog::db->set_file_path("storage.txt", storage_fp);
    MyDialog::db->set_file_path("data.txt", data_fp);

    FILE *fp = fopen(MyDialog::db->get_file_path("storage.txt").c_str(), "r");

    Node *tmp_root = MyDialog::db->get_root();

    // first, we check if there is any bytes in the storage file
    int size_storage = GetFileSize("storage.txt");

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

        // getting all of the nodes from the storage file into an array
        MyDialog::db->PreOrderTravRebuild(tmp_root);

        std::vector<struct Node*> all_nodes_storage = MyDialog::db->get_preorder_trav_rebuild();
        for (auto n : all_nodes_storage) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            std::string key_str = MyDialog::db->ConvertToStr(n->key);
            std::string value_str = MyDialog::db->ConvertToStr(n->value);
            ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(key_str)));
            ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(value_str)));
        }
    }

    qDebug() << "Initial data file size " + QString::fromStdString(std::to_string(GetFileSize("data.txt")));

    std::string data_file = "data.txt";
    std::fstream streamer(data_file, std::ios::in | std::ios::out);

    ui->pushButton->setText("GET");
    ui->pushButton_2->setText("POST");
    ui->pushButton_3->setText("PUT");
    ui->pushButton_4->setText("DELETE");

    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget_2->setColumnWidth(1, 100);
}

// after we close the application, we need to make sure that we save the information
// in the data file into the storage file so that we can persistently save the
// entries upon future use
DBWindow::~DBWindow()
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

//the purpose of this is that it allows us to switch between the windows ie the login window and databasewindow
void DBWindow::set_partner(LoginWindow *partner) {
    if (partner == 0) {
        return;
    }

    if (lw_partner != partner) {
        if (lw_partner != 0) {
            disconnect(ui->home_label, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(ui->home_label, SIGNAL(clicked()), (QObject*)lw_partner, SLOT(show()));
            disconnect(ui->home_label, SIGNAL(clicked()), (QObject*)lw_partner, SLOT(reset_line_edits()));
        }

        lw_partner = partner;

        connect(ui->home_label, SIGNAL(clicked()), this, SLOT(hide()));
        connect(ui->home_label, SIGNAL(clicked()), (QObject*)lw_partner, SLOT(show()));
        connect(ui->home_label, SIGNAL(clicked()), (QObject*)lw_partner, SLOT(reset_line_edits()));
    }
}

// this fills up the user table
// we can assume that by this point, the li field of the
// lw_partner is filled up so we can just use that information
// in order to fill the ui user table
void DBWindow::FillUserTable() {
    for ( auto it = lw_partner->li->table.begin(); it != lw_partner->li->table.end(); ++it  )
    {
       std::cout << it->first << '\t' << it->second << std::endl;
       ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
       ui->tableWidget_2->setItem (ui->tableWidget_2->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(it->first)));
       ui->tableWidget_2->setItem (ui->tableWidget_2->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(it->second)));
    }
}

// this method gets called when the login window switches over to the database window
// in order to set visiblity/enability of the delete user button, the toggle user table button, and
// user table
void DBWindow::set_ui() {
    if (lw_partner->li->user_is_admin == true) {
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->tableWidget_2->setVisible(false);
    } else {
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->tableWidget_2->setVisible(false);
    }
}

// this launches the GET request dialog
void DBWindow::on_pushButton_clicked()
{
    REST_TYPE type = GET;
    QDialog* gd = DialogFactory::Create(type);
    connect(gd, SIGNAL(SendGetRes(Response)), this, SLOT(HandleGetRes(Response)));

    gd->setModal(true);
    gd->exec();
}

// this is the callback function of when the user submits a get request
void DBWindow::HandleGetRes(Response res)
{
    qDebug() << GetFileSize("data.txt");
    ui->response_message_2->setText("");
    //if signal is recieved prints good messages. Else error messages
    if (res.successful) {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message_1->setText(res.body_info);
    } else {
        ui->response_stat->setText("BAD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        ui->response_message_1->setText(res.body_info);
    }
}

// this launches the POST request dialog
void DBWindow::on_pushButton_2_clicked()
{
    REST_TYPE type = POST;
    QDialog* pd = DialogFactory::Create(type);
    connect(pd, SIGNAL(SendPostRes(std::string, std::string, Response)), this, SLOT(HandlePostRes(std::string, std::string, Response)));

    pd->setModal(true);
    pd->exec();
}

// this is the callback function of when the user submits a post request
void DBWindow::HandlePostRes(std::string key, std::string value, Response res)
{
    qDebug() << GetFileSize("data.txt");
    ui->response_message_2->setText("");
    if (res.successful) {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message_1->setText(res.body_info);

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(key)));
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(value)));
    } else {
        ui->response_stat->setText("BAD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        ui->response_message_1->setText(res.body_info);
    }
}

// this launches the PUT request dialog
void DBWindow::on_pushButton_3_clicked()
{
    REST_TYPE type = PUT;
    QDialog* pd = DialogFactory::Create(type);
    connect(pd, SIGNAL(SendPutRes(std::string, std::string, Response)), this, SLOT(HandlePutRes(std::string, std::string, Response)));

    pd->setModal(true);
    pd->exec();
}

// this is the callback function of when the user submits a put request
void DBWindow::HandlePutRes(std::string key, std::string value, Response res)
{
    qDebug() << GetFileSize("data.txt");
    std::string res_str = res.body_info.toLocal8Bit().constData();
    std::vector<std::string> vec_res_str;

    std::stringstream ss(res_str);
    //this is a way to put a string into a vector without including the dollar signs
    while(ss.good()) {
        std::string substr;
        getline(ss, substr, '$');
        vec_res_str.push_back(substr);
    }

    //positive messageif succesful
    if (!res.successful) {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message_1->setText(res.body_info);
        ui->response_message_2->setText("");

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(key)));
        ui->tableWidget->setItem (ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(value)));
    } else {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message_1->setText(QString::fromStdString(vec_res_str[0]));
        ui->response_message_2->setText(QString::fromStdString(vec_res_str[1]));

        int row_key = GetRowEntry(res.put_update_key, 1);

        ui->tableWidget->item(row_key, 1)->setText(res.put_update_value);
    }
}

// this launches the DELETE request dialog
void DBWindow::on_pushButton_4_clicked()
{
    //factory design pattern
    REST_TYPE type = DELETE;
    QDialog* dd = DialogFactory::Create(type);
    connect(dd, SIGNAL(SendDelRes(Response)), this, SLOT(HandleDelRes(Response)));

    dd->setModal(true);
    dd->exec();
}

// this is the callback function of when the user submits a delete request
void DBWindow::HandleDelRes(Response res)
{
    qDebug() << GetFileSize("data.txt");
    ui->response_message_2->setText("");
    if (res.successful) {
        ui->response_stat->setText("GOOD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 180, 0);}"));
        ui->response_message_1->setText(res.body_info);

        int row_key = GetRowEntry(res.delete_key, 1);

        ui->tableWidget->removeRow(row_key);
    } else {
        ui->response_stat->setText("BAD");
        ui->response_stat->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        ui->response_message_1->setText(res.body_info);
    }
}

//ui for delete user button in database window ui
void DBWindow::on_pushButton_5_clicked()
{
    DeleteUserDialog* dud = new DeleteUserDialog();
    connect(dud, SIGNAL(SendDelUserRes(Response)), this, SLOT(HandleDelUserRes(Response)));
    dud->setModal(true);
    dud->exec();
}

// this is the callback function for when the user(admin) successfully deletes a user
void DBWindow::HandleDelUserRes(Response res) {
    if (res.successful == true) {
        int row_key = GetRowEntry(res.body_info, 2);
        ui->tableWidget_2->removeRow(row_key);
    }
}

// this toggles the user table
void DBWindow::on_pushButton_6_clicked()
{
    PasswordDialog* pd = new PasswordDialog();
    connect(pd, SIGNAL(SendShowUTRes(Response)), this, SLOT(HandleShowUTRes(Response)));
    pd->setModal(true);
    pd->exec();

    bool next_state = !ui->tableWidget_2->isVisible();
    ui->tableWidget_2->setVisible(next_state);
}
