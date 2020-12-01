#include "deleteuserdialog.h"
#include "ui_deleteuserdialog.h"
#include "logininterface.h"
#include <iostream>


DeleteUserDialog::DeleteUserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteUserDialog)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("Enter user");
}

DeleteUserDialog::~DeleteUserDialog()
{
    delete ui;
}

//first we check if the user is an admin. If not then it wont be able to delete users
//if the user is an admin then it will be able to delete
void DeleteUserDialog::on_pushButton_clicked()
{
    std::map<std::string, std::string>::iterator it;
    std::string user_to_delete = ui->textEdit->toPlainText().toLocal8Bit().constData();

    //if user is an admin
    if (LoginInterface::user_is_admin == true)
    {
        it = LoginInterface::table.find(user_to_delete);
        //if it finds the user before it reaches end of table,remove
        if (it != LoginInterface::table.end())
        {
            std::string full_line = user_to_delete + " " + LoginInterface::table.find(user_to_delete)->second;
            //remove from table
            LoginInterface::table.erase(it);
            //remove from file
            LoginInterface::DeleteUserFromFile(full_line);
            Response res;
            res.successful = true;
            res.body_info = QString::fromStdString(user_to_delete);
            emit SendDelUserRes(res);
            close();
        } else {
            std::cout << "user doesn't exist" << std::endl;
            ui->label->setText("User doesn't exist");
            ui->label->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        }
    } else {
        std::cout << "user not allowed to delete" << std::endl;
    }
}

