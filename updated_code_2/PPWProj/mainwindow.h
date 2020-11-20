#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "databasebst.h"
#include "loginwindow.h"
#include <QMainWindow>
#include "qobject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void set_partner(LoginWindow* partner);
    std::string GetFilePath(std::string file_name);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    int GetRowEntry(QString key);

    void HandleGetRes(Response res);
    void HandlePostRes(std::string key, std::string value, Response res);
    void HandlePutRes(std::string key, std::string value, Response res);
    void HandleDelRes(Response res);

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    LoginWindow *lw_partner;
};
#endif // MAINWINDOW_H
