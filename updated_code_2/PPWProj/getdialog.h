#ifndef GETDIALOG_H
#define GETDIALOG_H

#include "mydialog.h"
#include <QDialog>
#include <QString>

namespace Ui {
class GetDialog;
}

class GetDialog : public QDialog, public MyDialog {
    Q_OBJECT
public:
    explicit GetDialog(std::string input_type, QWidget *parent = nullptr);
    Response DoRequest();
    ~GetDialog();

private slots:

    void on_pushButton_clicked();

signals:
    void SendGetRes(Response res);

private:
    Ui::GetDialog *ui;
};

#endif // GETDIALOG_H
