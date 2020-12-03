#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

//setting up ui
LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    dbw_partner(0),
    called_fill(false),
    in_login_mode(true),
    in_sign_up_mode(false)
{
    ui->setupUi(this);
    ui->label_password_2->setVisible(false);
    ui->lineEdit_password_2->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

//This is a helper function. Based on whether the user is logging in or trying to go back to the loggin page window, this function helps us do that.
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
        if (called_fill == false) {
            // we only want to call the fill function once
            do_fill_function(dbw_partner);
            called_fill = true;
        } else if (called_fill == true && !login_resp.new_user.empty()) {
            // if we already filled the user table and there exists a new_user entry
            // in the login_resp, this must mean that we just did successive sign up
            // so, we want to call
            do_add_user_function(dbw_partner);
        }
        do_set_ui_function(dbw_partner);
    } else {
        if (login_resp.body_info.size() < 2) {
            ui->label_2->setText(QString::fromStdString(login_resp.body_info[0]));
            ui->label_2->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
            ui->label_3->setText("");
        } else {
            ui->label_2->setText(QString::fromStdString(login_resp.body_info[0]));
            ui->label_2->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
            ui->label_3->setText(QString::fromStdString(login_resp.body_info[1]));
            ui->label_3->setStyleSheet(QStringLiteral("QLabel{color: rgb(180, 0, 0);}"));
        }
    }
}

// this method gets called whenever we switch from the database window to the login window
// we need to make sure that the line edit fields are reset so that the next user
// can login/sign up
// this is method is also called whenever we switch between login mode and sign up mode
void LoginWindow::reset_fields() {
    ui->lineEdit_username->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_password_2->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
}

// this sets the default ui of the login page, which consists of
// the login menu and not the sign up menu
void LoginWindow::default_login_page() {
    in_sign_up_mode = false;
    in_login_mode = true;
    ui->pushButton_login->setGeometry(90, 210, 120, 25);
    ui->pushButton_signup->setGeometry(90, 260, 120, 25);
    ui->label_password->setGeometry(40, 120, 67, 17);
    ui->lineEdit_password->setGeometry(40, 150, 221, 25);
    ui->label_password_2->setVisible(false);
    ui->lineEdit_password_2->setVisible(false);
}

//ui for login button
void LoginWindow::on_pushButton_login_clicked()
{
    // we can set this as false because we know that it's not
    // possible to create admin users
    li->user_is_admin = false;
    if (in_login_mode == true) {
        std::string username = ui->lineEdit_username->text().toLocal8Bit().constData();
        std::string password = ui->lineEdit_password->text().toLocal8Bit().constData();
        LoginResp lr;
        // for some reason, the dbw_partner becomes null when doing the Login()
        // method, so just creating a copy of it here so that
        // I can reassign the dbw_partner
        DBWindow* copy_partner = dbw_partner;
        lr = li->Login(username, password);
        dbw_partner = copy_partner;
        emit SendLoginResp(lr);
    } else {
        in_sign_up_mode = false;
        in_login_mode = true;
        ui->pushButton_login->setGeometry(90, 210, 120, 25);
        ui->pushButton_signup->setGeometry(90, 260, 120, 25);
        ui->label_password->setGeometry(40, 120, 67, 17);
        ui->lineEdit_password->setGeometry(40, 150, 221, 25);
        ui->label_password_2->setVisible(false);
        ui->lineEdit_password_2->setVisible(false);
        // resetting the fields
        reset_fields();
    }
}

//ui for signup button
void LoginWindow::on_pushButton_signup_clicked()
{
    if (in_sign_up_mode == false) {
        in_login_mode = false;
        in_sign_up_mode = true;
        ui->pushButton_login->setGeometry(20, 260, 120, 25);
        ui->pushButton_signup->setGeometry(160, 260, 120, 25);
        ui->label_password->setGeometry(40, 110, 67, 17);
        ui->lineEdit_password->setGeometry(40, 140, 221, 25);
        ui->label_password_2->setVisible(true);
        ui->lineEdit_password_2->setVisible(true);

        // resetting the fields
        reset_fields();
    } else {
        std::string username = ui->lineEdit_username->text().toLocal8Bit().constData();
        std::string password = ui->lineEdit_password->text().toLocal8Bit().constData();
        std::string re_password = ui->lineEdit_password_2->text().toLocal8Bit().constData();

        LoginResp lr;
        if (password != re_password) {
            lr.succ = false;
            lr.is_admin = false;
            lr.body_info[0] = "Passwords don't match";
            emit SendLoginResp(lr);
        } else {
            DBWindow* copy_partner = dbw_partner;
            lr = li->WriteFile(username, password);
            dbw_partner = copy_partner;
            emit SendLoginResp(lr);
        }
    }
}
