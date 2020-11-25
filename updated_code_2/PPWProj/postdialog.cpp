#include "postdialog.h"
#include "ui_postdialog.h"
#include <QtDebug>

//ui for post button
PostDialog::PostDialog(std::string input_type, QWidget *parent) :
    QDialog(parent),
    MyDialog(input_type),
    ui(new Ui::PostDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
    ui->textEdit->setPlaceholderText("Insert a key");
    ui->textEdit_2->setPlaceholderText("Insert a value");
}

PostDialog::~PostDialog()
{
    delete ui;
}

void PostDialog::on_pushButton_clicked()
{
    std::string key_str = ui->textEdit->toPlainText().toLocal8Bit().constData();
    set_key(key_str);
    std::string value_str = ui->textEdit_2->toPlainText().toLocal8Bit().constData();
    set_value(value_str);
    //calls appropriate function for writing to the database
    Response r = DoRequest();
    emit SendPostRes(key_str, value_str, r);
}

//writes to the database. It finds the proper place to put the node in on our bst.
Response PostDialog::DoRequest()
{
    Node* temp_root = db->get_root();
    unsigned long hash = db->CreateHash(get_key());
    Node* temp_node = db->SearchNode(temp_root, hash);

    reset_key_value_vecs();
    fill_key_value_vecs();

    if (temp_node == nullptr) {
        int spot_idx = db->FindFreeSpace();
        std::cout << "The spot idx is " << std::to_string(spot_idx) << std::endl;
        db->set_root(db->Insert(db->get_root(), hash, get_key_vec(), get_value_vec(), spot_idx * 80));

        return Response(true, "Added new key/value to database");
    } else {
        return Response(false, "Error. Please enter a new key");
    }
}
