#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //transfer
    void login();
    void readFile();


private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

protected:
    bool isAdmin = false;
    std::map<std::string, std::string> table;

private:
    Ui::MainWindow *ui;
    std::string userAttempt;
    std::string passwordAttempt;
    std::string writePassword;
    std::string writeUser;
    bool accessGranted = false;
    Dialog *secDialog;

};

#endif // MAINWINDOW_H
