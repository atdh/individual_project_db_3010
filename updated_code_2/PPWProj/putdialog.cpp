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
    std::string key_str = ui->textEdit->toPlainText().toLocal8Bit().constData();
    set_key(key_str);
    std::string value_str = ui->textEdit_2->toPlainText().toLocal8Bit().constData();
    set_value(value_str);

    Response r = DoRequest();
    emit SendPutRes(key_str, value_str, r);
}

Response PutDialog::DoRequest()
{
    Node* temp_root = db->get_root();
    unsigned long hash = db->CreateHash(get_key());
    Node* temp_node = db->SearchNode(temp_root, hash);

    reset_key_value_vecs();
    fill_key_value_vecs();

    if (temp_node == NULL) {
        int spot_idx = db->FindFreeSpace();
        std::cout << "The spot idx is " << std::to_string(spot_idx) << std::endl;
        db->set_root(db->Insert(db->get_root(), hash, get_key_vec(), get_value_vec(), spot_idx * 80));

        return Response(false, "Key doesn't exist. Adding it");
    } else {
        std::string res_str = "Key exists already. Updating value from$" + db->ConvertToStr(temp_node->value);
        res_str += " to " + get_value();
        db->Update(temp_node, get_value_vec());

        Response r(true, QString::fromStdString(res_str));
        r.put_update_key = QString::fromStdString(get_key());
        r.put_update_value = QString::fromStdString(get_value());
        return r;
    }
}
