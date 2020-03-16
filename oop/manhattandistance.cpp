#include "manhattandistance.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <QDebug>

ManhattanDistance::ManhattanDistance()
{

}

string ManhattanDistance::solve(string s)
{
    stringstream ss;
    string ans;
    int s1, t;
    double v1, v2;

    ss<<s;
    ss>>s1>>t>>v1>>v2;

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

    query.exec("SELECT ROUND(MAX(a.LON)-MIN(a.LON)+MAX(b.LAT)-MIN(b.LAT), 4) FROM "
               "(SELECT * FROM citytable "
               "WHERE LAT<" +QString::number(v1)+
               " ORDER BY LAT DESC "
               "LIMIT " +QString::number(s1-1)+", "+QString::number(t-s1+1)+") AS a, "
               "(SELECT * FROM citytable "
               "WHERE LON>" +QString::number(v2)+
               " ORDER BY LON ASC "
               "LIMIT " +QString::number(s1-1)+", "+QString::number(t-s1+1)+") AS b");

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
