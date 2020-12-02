#ifndef DBWINDOW_H
#define DBWINDOW_H
#include <vector>
#include "databasebst.h"
#include "loginwindow.h"
#include <QMainWindow>
#include "qobject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DBWindow; }
QT_END_NAMESPACE

class DBWindow : public QMainWindow
{
    Q_OBJECT

public:
    DBWindow(QWidget *parent = nullptr);
    void set_partner(LoginWindow* partner);
    std::string GetFilePath(std::string file_name);
    void FillUserTable();
    void AddMoreSignup();
    void set_ui();
    friend LoginWindow;
    ~DBWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    int GetRowEntry(QString key, int table_num);

    void HandleGetRes(Response res);
    void HandlePostRes(std::string key, std::string value, Response res);
    void HandlePutRes(std::string key, std::string value, Response res);
    void HandleDelRes(Response res);
    void HandleDelUserRes(Response res);
    void HandleShowUTRes(bool);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::DBWindow *ui;
    LoginWindow *lw_partner;
};
#endif // DBMAINWINDOW_H
