#include "median.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <QDebug>

Median::Median()
{

}

string Median::solve(string s)
{
    stringstream ss;
    string ans;
    int a, b, m;
    string lat, asc;

    ss<<s;
    ss>>a>>b>>lat>>m>>asc;

    asc = (asc=="asc"? "ASC" : "DESC");

    QSqlQuery query;
    query.exec("drop database if exists CITYDATABASE");
    query.exec("create database if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
    query.exec("drop CITYTABLE if exists CITYDATABASE");
    query.exec("create table CITYTABLE (ID int, COUNTRY varchar(50), CITY varchar(60), LAT double, LON double, primary key(ID))");
    query.exec("use CITYTABLE");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' "
               "INTO TABLE CITYTABLE "
               "FIELDS TERMINATED BY ',' "
               "ENCLOSED BY '\"' "
               "LINES TERMINATED BY '\r\n' "
               "IGNORE 1 ROWS");

    query.exec("SELECT ROUND(AVG("+QString::fromStdString(lat)+"), 4) FROM "
               "(SELECT ROW_NUMBER() OVER(ORDER BY "+QString::fromStdString(lat)+" "+QString::fromStdString(asc)+") as r, "+QString::fromStdString(lat)+", x FROM "
               "((SELECT "+QString::fromStdString(lat)+" FROM CITYTABLE "
               "WHERE ID LIKE '%"+QString::number(m)+"' "
               "ORDER BY "+QString::fromStdString(lat)+" "+QString::fromStdString(asc)+" "
               "LIMIT "+QString::number(a-1)+", "+QString::number(b-a+1)+") "
               "UNION ALL "
               "(SELECT "+QString::fromStdString(lat)+" FROM CITYTABLE "
               "WHERE ID LIKE '%"+QString::number(m)+"' "
               "ORDER BY "+QString::fromStdString(lat)+" "+QString::fromStdString(asc)+" "
               "LIMIT "+QString::number(a-1)+", "+QString::number(b-a+1)+") "
               "ORDER BY "+QString::fromStdString(lat)+" "+QString::fromStdString(asc)+") AS b, "
               "((SELECT COUNT("+QString::fromStdString(lat)+") AS x FROM "
               "(SELECT "+QString::fromStdString(lat)+" FROM CITYTABLE "
               "WHERE ID LIKE '%"+QString::number(m)+"' "
               "ORDER BY "+QString::fromStdString(lat)+" "+QString::fromStdString(asc)+" "
               "LIMIT "+QString::number(a-1)+", "+QString::number(b-a+1)+") AS a)) AS c) AS d "
               "WHERE r=x OR r=x+1");

    query.next();
    if(query.isNull(0))
        ans="NULL";
    else
    {
        stringstream ss1;
        ss1<<fixed<<setprecision(4)<<query.value(0).toDouble();
        ans=ss1.str();
    }

    return ans;
}
