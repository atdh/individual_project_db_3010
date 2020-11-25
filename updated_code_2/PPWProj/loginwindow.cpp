#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    dbw_partner(0),
    li(new LoginInterface())
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::set_partner(DBWindow *partner) {
    if (partner == 0) {
        return;
    }

    if (dbw_partner != partner) {
        if (dbw_partner != 0) {
            disconnect(this, SIGNAL(SendLoginResp(LoginResp)), this, SLOT(window_switcher(LoginResp)));
//            disconnect(ui->pushButton_login, SIGNAL(clicked()), (QObject*)dbw_partner, SLOT(show()));
        }

        dbw_partner = partner;

        connect(this, SIGNAL(SendLoginResp(LoginResp)), this, SLOT(window_switcher(LoginResp)));
//        connect(ui->pushButton_login, SIGNAL(clicked()), (QObject*)dbw_partner, SLOT(show()));
    }
}

void LoginWindow::window_switcher(LoginResp login_resp) {
    qDebug() << "entered the window switcher";
    if (login_resp.succ == true) {
        hide();
        do_function_2(dbw_partner);
    } else {
        std::cout << "didn't work" << std::endl;
    }
}

void LoginWindow::on_pushButton_login_clicked()
{
    std::string username = ui->lineEdit_username->text().toLocal8Bit().constData();
    std::string password = ui->lineEdit_password->text().toLocal8Bit().constData();
    LoginResp lr;
    lr = li->Login(username, password);
    emit SendLoginResp(lr);
}
