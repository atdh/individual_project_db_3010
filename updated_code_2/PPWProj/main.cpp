#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtCore>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("My Database");
    w.show();
    return a.exec();
}
