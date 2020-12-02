#ifndef DELETEUSERDIALOG_H
#define DELETEUSERDIALOG_H

#include <QDialog>
#include "databasebst.h"

namespace Ui {
class DeleteUserDialog;
}

class DeleteUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteUserDialog(QWidget *parent = nullptr);
    ~DeleteUserDialog();

private slots:
    void on_pushButton_clicked();

signals:
    void SendDelUserRes(Response res);

private:
    Ui::DeleteUserDialog *ui;
};

#endif // DELETEUSERDIALOG_H
