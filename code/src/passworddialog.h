#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>
#include "logininterface.h"

namespace Ui {
class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordDialog(QWidget *parent = nullptr);
    ~PasswordDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void SendShowUTRes(bool); // send a bool to indicate whether the user entered the password correctly

private:
    Ui::PasswordDialog *ui;
};

#endif // PASSWORDDIALOG_H
