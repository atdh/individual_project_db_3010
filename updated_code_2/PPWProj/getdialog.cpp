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
    qDebug() << r.body_info;
}

Response GetDialog::DoRequest()
{
    Node* temp_root = db->get_root();
    unsigned long hash = db->CreateHash(get_key());
    Node* temp_node = db->SearchNode(temp_root, hash);

    if (temp_node != NULL)
    {
        std::cout << "The key was found in the database" << std::endl;
        int size = (sizeof(temp_node->value) / sizeof(char));
        std::string value = db->convertToStr(temp_node, size);
        std::cout << "The corresponding value is " + value << std::endl;

        return Response(true, "The get request was successful");
    } else {
        std::cout << "The key doesn't exist in the database" << std::endl;

        return Response(false, "The get request wasn't successful");
    }
}
