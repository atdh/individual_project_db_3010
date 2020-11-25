#include "dbwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBWindow dbw;
    LoginWindow lw;

    dbw.set_partner(&lw);
    lw.set_partner(&dbw);

    dbw.setWindowTitle("My Database");

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int x = (screenWidth - 810) / 2;
    int y = (screenHeight - 500) / 2;

    dbw.move(x,y);
    lw.move(x,y);

    lw.show();
    return a.exec();
}
