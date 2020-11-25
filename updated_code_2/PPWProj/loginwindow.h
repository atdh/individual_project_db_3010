#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "logininterface.h"

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
    void set_function_2(void (*b)(DBWindow* dbw_input)) {
        bar = b;
    }
    void do_function_2(DBWindow* dbw_input) {
        (*bar)(dbw_input);
    }
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();
    void window_switcher(LoginResp login_resp);

signals:
    void SendLoginResp(LoginResp login_resp);

private:
    Ui::LoginWindow *ui;
    DBWindow* dbw_partner;
    LoginInterface* li;
    void (*foo)(int);
    void (*bar)(DBWindow*);
};

#endif // LOGINWINDOW_H
