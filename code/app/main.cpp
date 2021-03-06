#include "dbwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QDesktopWidget>
#include "logininterface.h"

//this allowed us to help change the window. It's a helper function.
void open_dbw(DBWindow* dbw_input) {
    dbw_input->show();
}

// this allows us to call the database window's fill user table
void fill_user_table(DBWindow* dbw_input) {
    dbw_input->FillUserTable();
}

// this allows us to call the database window's set_ui() method
// which will enable/disable certain ui components
// depending on whether the user is an admin
void set_up_ui_user(DBWindow* dbw_input) {
    dbw_input->set_ui();
}

// this allows us to the database window's AddMoreSignup() method
// which will add users to the user table when more than one person
// signs up
void add_new_user(DBWindow* dbw_input) {
    dbw_input->AddMoreSignup();
}

//keeps track of all users
std::map<std::string, std::string> LoginInterface::table;
//keeps track of which users are admins and which ones are not
std::unordered_set<std::string> LoginInterface::admin_set;

bool LoginInterface::user_is_admin = false;
std::string LoginInterface::username = "";
std::string LoginInterface::password = "";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //making objects
    DBWindow dbw;
    LoginWindow lw;

    LoginInterface::ReadFile();
    //setting partner ie: login/signupwindow and databasewindow
    dbw.set_partner(&lw);
    lw.set_partner(&dbw);
    lw.set_show_function(open_dbw);
    lw.set_fill_ut_function(fill_user_table);
    lw.set_set_ui_function(set_up_ui_user);
    lw.set_add_user_function(add_new_user);

    //setting our ui dimension
    dbw.setWindowTitle("My Database");
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int x = (screenWidth - 810) / 2; // 810 comes from the width I set the window screen to
    int y = (screenHeight - 500) / 2; // 500 comes from the height I set the window screen to

    dbw.move(x,y);
    lw.move(x,y);

    lw.show();

    return a.exec();
}
