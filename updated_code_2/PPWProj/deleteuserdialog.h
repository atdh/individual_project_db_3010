#ifndef DELETEUSERDIALOG_H
#define DELETEUSERDIALOG_H

#include <QDialog>

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

private:
    Ui::DeleteUserDialog *ui;
};

#endif // DELETEUSERDIALOG_H
