#ifndef POSTDIALOG_H
#define POSTDIALOG_H

#include <QDialog>
#include "mydialog.h"

namespace Ui {
class PostDialog;
}

class PostDialog : public QDialog, public MyDialog
{
    Q_OBJECT

public:
    explicit PostDialog(std::string input_type, QWidget *parent = nullptr);
    Response DoRequest();
    ~PostDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void AddKeyVal(std::string key, std::string value, Response res);

private:
    Ui::PostDialog *ui;
};

#endif // POSTDIALOG_H
