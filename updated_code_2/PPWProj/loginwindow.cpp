#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

//setting up ui
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    dbw_partner(0)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//This is a helper funciton. Based on whether the user is logging in or trying to go back to the loggin page window, this function helps us do that.
//It allows us to switch to the proper windows
void LoginWindow::set_partner(DBWindow *partner) {
    if (partner == 0) {
        return;
    }

    if (dbw_partner != partner) {
        if (dbw_partner != 0) {
            disconnect(this, SIGNAL(SendLoginResp(LoginResp)), this, SLOT(window_switcher(LoginResp)));
        }

        dbw_partner = partner;

        connect(this, SIGNAL(SendLoginResp(LoginResp)), this, SLOT(window_switcher(LoginResp)));
    }
}

//Hides window or shows window accordignly for a smooth ui experience.
void LoginWindow::window_switcher(LoginResp login_resp) {
    if (login_resp.succ == true) {
        hide();
        do_show_function(dbw_partner);
        do_fill_function(dbw_partner);
        do_set_ui_function(dbw_partner);
    } else {

    }
}

void LoginWindow::reset_line_edits() {
    ui->lineEdit_username->setText("");
    ui->lineEdit_password->setText("");
}

//ui for login button
void LoginWindow::on_pushButton_login_clicked()
{
    std::string username = ui->lineEdit_username->text().toLocal8Bit().constData();
    std::string password = ui->lineEdit_password->text().toLocal8Bit().constData();
    LoginResp lr;
    lr = li->Login(username, password);
    emit SendLoginResp(lr);
}

//ui for signup button
void LoginWindow::on_pushButton_signup_clicked()
{
    std::string username = ui->lineEdit_username->text().toLocal8Bit().constData();
    std::string password = ui->lineEdit_password->text().toLocal8Bit().constData();
    LoginResp lr;
    lr = li->WriteFile(username, password);
    emit SendLoginResp(lr);
}
