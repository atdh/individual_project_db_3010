#include "postdialog.h"
#include "ui_postdialog.h"
#include <QtDebug>

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

    Response r = DoRequest();
    qDebug() << r.body_info;
    emit AddKeyVal(key_str, value_str, r);
}

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

        return Response(true, "Successfully added a new key/value to the database");
    } else {
        std::cout << "Sorry, but the key is already in the database. Please enter a unique key" << std::endl;
        return Response(false, "Please enter a new key to the database");
    }
}
