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

    // these setter and doer functions is a work-around that I came up with
    // in order to get around the issue of "member access into incomplete type"
    // error, which arises because of the dependency relationship of the LoginWindow
    // and the DBWindow
    // because of this, I can't simply do "dbw_input->show()" for instance
    // because the show() method hasn't been incorporated yet
    // so, the work-around is that DBWindow's method are fully defined
    // in the main.cpp file but not in the loginwindow.h file, so
    // I created functions which take in a function as a parameter which
    // is a wrapper function around one of the methods of DBWindow
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
    void do_set_ui_function(DBWindow* dbw_input) {
        (*set_ui_func)(dbw_input);
    }
    void set_add_user_function(void (*auf)(DBWindow* dbw_input)) {
        add_user_func = auf;
    }
    void do_add_user_function(DBWindow* dbw_input) {
        (*add_user_func)(dbw_input);
    }
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();
    void window_switcher(LoginResp login_resp);
    void reset_fields();
    void default_login_page();

    void on_pushButton_signup_clicked();

signals:
    void SendLoginResp(LoginResp login_resp);

private:
    Ui::LoginWindow *ui;
    DBWindow* dbw_partner;
    void (*show_func)(DBWindow*);
    void (*fill_ut_func)(DBWindow*);
    void (*set_ui_func)(DBWindow*);
    void (*add_user_func)(DBWindow*);
    bool called_fill;

    // since im reusing the ui for the login button, I'm including a boolean
    // to indicate whether we are in login mode
    // if we are in login mode, we are actually going to login
    bool in_login_mode;

    // since im reusing the ui for the sign up button, I'm including a boolean
    // to indicate whether we are in sign up mode
    // if we are in sign up mode, we are actually going to add a new user
    bool in_sign_up_mode;
};

#endif // LOGINWINDOW_H
