#include "deletedialog.h"
#include "ui_deletedialog.h"

DeleteDialog::DeleteDialog(std::string input_type, QWidget *parent) :
    QDialog(parent),
    MyDialog(input_type),
    ui(new Ui::DeleteDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
}

DeleteDialog::~DeleteDialog()
{
    delete ui;
}
