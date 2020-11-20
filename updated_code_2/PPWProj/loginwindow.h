#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

class MainWindow;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void set_partner(MainWindow* partner);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow* mw_partner;
};

#endif // LOGINWINDOW_H
