#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vector>
#include "databasebst.h"
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
    std::string GetFilePath(std::string file_name);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void HandleGetRes(Response res);
    void HandlePostRes(std::string key, std::string value, Response res);
    void HandlePutRes(std::string key, std::string value, Response res);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
