#include "easycity1.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <QDebug>

using namespace std;

EasyCity1::EasyCity1()
{

}

string EasyCity1::solve(string s)
{
    stringstream ss;
    string ans;
    string ch, ev, even, asc;
    double la, lo, p, q;
    int m, n;
    int t1, t2;

    ss<<s;
    ss>>ch>>la>>lo>>p>>q>>ev>>m>>even>>asc>>n;

    t1 = (ev=="ev"? 0 : 1);
    t2 = (even=="even"? 0 : 1);
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

    query.exec("SELECT COUNT(CITY)-COUNT(DISTINCT CITY)FROM citytable "
               "WHERE CITY REGEXP '^[" + QString::fromStdString(ch) + "]' AND CITY REGEXP '[^aeiou]$' "
               "AND LAT>" + QString::number(la) + " AND LON<"+ QString::number(lo));

    query.next();
    if(query.isNull(0))
        ans = "NULL";
    else
        ans = query.value(0).toString().toStdString();

    query.exec("UPDATE CITYTABLE "
               "SET LAT=LAT*" + QString::number(p) + ", LON=LON*" + QString::number(q) +
               " WHERE ID%2=" + QString::number(t1));

    query.exec("SELECT ROUND(SUM(a.LAT), " + QString::number(n) + "), ROUND(SUM(a.LON), "+ QString::number(n)+ "), MAX(length(a.CITY))-MIN(length(a.CITY)) FROM "
               "(SELECT * FROM citytable "
               "WHERE ID%2=" + QString::number(t2) +
               " ORDER BY length(CITY) " + QString::fromStdString(asc) + ", CITY DESC "
               "LIMIT " + QString::number(m) +") AS a");

    query.next();
    for(int i = 0; i < 2; i++)
    {
        if(query.isNull(i))
            ans += " NULL";
        else
        {
            stringstream ss1;
            ss1<<fixed<<setprecision(n)<<query.value(i).toDouble();
            ans += " " + ss1.str();
        }
    }
    if(query.isNull(2))
        ans += " NULL";
    else
        ans += " " + query.value(2).toString().toStdString();

    return ans;
}
