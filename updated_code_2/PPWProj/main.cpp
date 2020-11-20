#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginWindow l;

    w.set_partner(&l);
    l.set_partner(&w);

    w.setWindowTitle("My Database");

    QDesktopWidget *desktop = QApplication::desktop();
    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int x = (screenWidth - 810) / 2;
    int y = (screenHeight - 500) / 2;

    w.move(x,y);
    l.move(x,y);

    w.show();
    return a.exec();
}
