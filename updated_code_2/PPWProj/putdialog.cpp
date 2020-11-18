#include "putdialog.h"
#include "ui_putdialog.h"

PutDialog::PutDialog(std::string input_type, QWidget *parent) :
    QDialog(parent),
    MyDialog(input_type),
    ui(new Ui::PutDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
    ui->textEdit->setPlaceholderText("Insert a key");
    ui->textEdit_2->setPlaceholderText("Insert a value");
}

PutDialog::~PutDialog()
{
    delete ui;
}

void PutDialog::on_pushButton_clicked()
{
    qDebug() << "Within put";
    std::string key_str = ui->textEdit->toPlainText().toLocal8Bit().constData();
    set_key(key_str);
    std::string value_str = ui->textEdit_2->toPlainText().toLocal8Bit().constData();
    set_value(value_str);
}

Response PutDialog::DoRequest()
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

        return Response(true, "The key doesn't exist in the database. Will add it");
    } else {
        std::cout << "Sorry, but the key is already in the database. Please enter a unique key" << std::endl;

        std::string val_str = "";
        for (int i = 0; i < (int)temp_node->value.size(); i++) {
            val_str += temp_node->value[i];
        }

        std::string res_str = "The key already exists. Will change the value from " + val_str + " to " + get_value();
        return Response(true, QString::fromStdString(res_str));
    }
}
