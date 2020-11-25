#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

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

void LoginWindow::set_partner(DBWindow *partner) {
    if (partner == 0) {
        return;
    }

    if (dbw_partner != partner) {
        if (dbw_partner != 0) {
            disconnect(ui->pushButton_login, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(ui->pushButton_login, SIGNAL(clicked()), (QObject*)dbw_partner, SLOT(show()));
        }

        dbw_partner = partner;

        connect(ui->pushButton_login, SIGNAL(clicked()), this, SLOT(hide()));
        connect(ui->pushButton_login, SIGNAL(clicked()), (QObject*)dbw_partner, SLOT(show()));
    }

}
