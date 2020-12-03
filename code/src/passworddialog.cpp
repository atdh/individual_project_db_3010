#include "passworddialog.h"
#include "ui_passworddialog.h"

PasswordDialog::PasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordDialog)
{
    ui->setupUi(this);
    ui->pushButton->setText("Submit");
    ui->textEdit->setPlaceholderText("Type your password");
}

PasswordDialog::~PasswordDialog()
{
    delete ui;
}

void PasswordDialog::on_pushButton_clicked()
{
    std::string entered_pw = ui->textEdit->toPlainText().toLocal8Bit().constData();
    if (entered_pw == LoginInterface::password) {
        emit SendShowUTRes(true);
        close();
    } else {
        ui->label->setText("Incorrect password");
        ui->label->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
    }
}
