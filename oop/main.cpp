#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("FINAL"); // schema name
    database.setUserName("root");
    database.setPassword("nctuece"); // your password
    database.setPort(3306);
    bool ok = database.open();

    if(ok)
        qDebug()<<"Successful Connection.";
    else
        qDebug()<<"Error: Cannot connect!!!";


    MainWindow w;

    w.show();

    return a.exec();
}
