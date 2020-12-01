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
    LoginInterface* li;
    bool user_is_admin;
    explicit LoginWindow(QWidget *parent = nullptr);
    void set_partner(DBWindow* partner);
    void set_show_function(void (*sf)(DBWindow* dbw_input)) {
        show_func = sf;
    }
    void do_show_function(DBWindow* dbw_input) {
        (*show_func)(dbw_input);
    }
    void set_fill_ut_function(void (*futf)(DBWindow* dbw_input)) {
        fill_ut_func = futf;
    }
    void do_fill_function(DBWindow* dbw_input) {
        (*fill_ut_func)(dbw_input);
    }
    void set_set_ui_function(void (*suif)(DBWindow* dbw_input)) {
        set_ui_func = suif;
    }
    void (do_set_ui_function(DBWindow* dbw_input)) {
        (*set_ui_func)(dbw_input);
    }
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();
    void window_switcher(LoginResp login_resp);
    void reset_line_edits();

    void on_pushButton_signup_clicked();

signals:
    void SendLoginResp(LoginResp login_resp);

private:
    Ui::LoginWindow *ui;
    DBWindow* dbw_partner;
    void (*show_func)(DBWindow*);
    void (*fill_ut_func)(DBWindow*);
    void (*set_ui_func)(DBWindow*);
};

#endif // LOGINWINDOW_H
