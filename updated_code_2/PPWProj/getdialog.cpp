#include "getdialog.h"
#include "ui_getdialog.h"
#include <QtDebug>
#include "mydialog.h"

GetDialog::GetDialog(std::string input_type, QWidget *parent) :
    QDialog(parent),
    MyDialog(input_type),
    ui(new Ui::GetDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
    ui->textEdit->setPlaceholderText("Insert a key");
}

GetDialog::~GetDialog()
{
    delete ui;
}

void GetDialog::on_pushButton_clicked()
{
    std::string key_str = ui->textEdit->toPlainText().toLocal8Bit().constData();
    set_key(key_str);

    Response r = DoRequest();
    emit SendGetRes(r);
}

Response GetDialog::DoRequest()
{
    Node* temp_root = db->get_root();
    unsigned long hash = db->CreateHash(get_key());
    Node* temp_node = db->SearchNode(temp_root, hash);

    if (temp_node != NULL)
    {
        std::string value = db->ConvertToStr(temp_node->value);
        std::string res_str =  "Found key in database. Value is " + value;

        return Response(true, QString::fromStdString(res_str));
    } else {
        return Response(false, "Error. Key doesn't exist");
    }
}
