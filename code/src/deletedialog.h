#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include "mydialog.h"
#include <QDialog>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QDialog, public MyDialog
{
    Q_OBJECT

public:
    explicit DeleteDialog(std::string input_type, QWidget *parent = nullptr);
    Response DoRequest();
    ~DeleteDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void SendDelRes(Response res);

private:
    Ui::DeleteDialog *ui;
};

#endif // DELETEDIALOG_H
