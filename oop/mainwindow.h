#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlResult>
#include <QSqlDatabase>
#include "building.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Q_OBJECT

//    void updateGUI();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
//    void update();
    void slot_update_data();

private:
    Ui::MainWindow *ui;
    Building building;
    Data windata;
    People people;

};
#endif // MAINWINDOW_H
