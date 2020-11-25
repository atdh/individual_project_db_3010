#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

class DBWindow;

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    void set_partner(DBWindow* partner);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    DBWindow* dbw_partner;
};

#endif // LOGINWINDOW_H
