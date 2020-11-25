#include "dbwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QDesktopWidget>
#include "logininterface.h"

//this allowed us to help change the window. It's a helper function.
void open_lw(LoginWindow* lw_input) {
    lw_input->show();
}

void open_dbw(DBWindow* dbw_input) {
    dbw_input->show();
}
//keeps track of all users
std::map<std::string, std::string> LoginInterface::table;
//keeps track of which users are admins and which ones are not
std::unordered_set<std::string> LoginInterface::admin_set;
bool LoginInterface::user_is_admin = false;

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
    lw.set_function_2(open_dbw);

    //setting our ui dimension
    dbw.setWindowTitle("My Database");
    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int x = (screenWidth - 810) / 2; // 810 comes from the width I set the window screen to
    int y = (screenHeight - 500) / 2; // 500 comes from the height I set the window screen to

    dbw.move(x,y);
    lw.move(x,y);

//    open_lw(&lw);
//    lw.do_function_2(&lw);
    lw.show();

    return a.exec();
}
