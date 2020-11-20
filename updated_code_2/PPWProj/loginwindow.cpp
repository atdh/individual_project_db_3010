#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    mw_partner(0)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{

}

void LoginWindow::set_partner(MainWindow *partner) {
    if (partner == 0) {
        return;
    }

    if (mw_partner != partner) {
        if (mw_partner != 0) {
            disconnect(ui->pushButton, SIGNAL(clicked()), this, SLOT(hide()));
            disconnect(ui->pushButton, SIGNAL(clicked()), (QObject*)mw_partner, SLOT(show()));
        }

        mw_partner = partner;

        connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(hide()));
        connect(ui->pushButton, SIGNAL(clicked()), (QObject*)mw_partner, SLOT(show()));
    }

}
