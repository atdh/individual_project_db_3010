#ifndef PUTDIALOG_H
#define PUTDIALOG_H

#include <QDialog>
#include "mydialog.h"

namespace Ui {
class PutDialog;
}

class PutDialog : public QDialog, public MyDialog
{
    Q_OBJECT

public:
    explicit PutDialog(std::string input_type, QWidget *parent = nullptr);
    Response DoRequest();
    ~PutDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void SendPutRes(std::string key, std::string value, Response res);

private:
    Ui::PutDialog *ui;
};

#endif // PUTDIALOG_H
