#include "easycity2.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <QDebug>

using namespace std;

EasyCity2::EasyCity2()
{

}

string EasyCity2::solve(string s)
{
    stringstream ss;
    string ans;
    int n;
    string lar, che, chs;
    double la, ha, lo, ho;
    int m;
    string sn;
    vector<int> v;
    QString qs;

    ss<<s;
    ss>>n>>lar>>chs>>che>>la>>ha>>lo>>ho>>m;

    lar = (lar=="lar"? "DESC" : "ASC");

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

    query.exec("SELECT MID(COUNTRY, 1, 3), COUNT(CITY) FROM CITYTABLE "
               "GROUP BY COUNTRY "
               "ORDER BY COUNT(CITY) " + QString::fromStdString(lar) +
               " LIMIT " +  QString::number(n-1) + ", 1");

    query.next();


    for(int i = 0; i < 2; i++)
    {
        if(query.value(i).isNull())
            ans += "NULL ";
        else
            ans += query.value(i).toString().toStdString() + " ";
    }

    query.exec("DELETE FROM CITYTABLE "
               "WHERE ((CITY REGEXP '["+QString::fromStdString(che)+"]$|^[^"+QString::fromStdString(chs)+"]') "
               "OR ((LAT>="+QString::number(la)+" AND LAT<="+QString::number(ha)+") AND (LON>="+QString::number(lo)+" AND LON<="+QString::number(ho)+")))");

    query.exec("UPDATE CITYTABLE AS a, CITYTABLE AS b "
               "SET a.LON = b.LAT, b.LAT = a.LON "
               "WHERE a.ID=b.ID AND (a.ID LIKE '%"+QString::number(m)+"' AND b.ID LIKE '%"+QString::number(m)+"')");

    query.exec("SELECT ROUND(SQRT(POW(MAX(LON)-MIN(LON), 2)+POW(MAX(LAT)-MIN(LAT), 2)), 4) FROM CITYTABLE");

    query.next();
    if(query.isNull(0))
        ans +="NULL";
    else
    {
        stringstream ss1;
        ss1<<fixed<<setprecision(4)<<query.value(0).toDouble();
        ans += ss1.str();
    }

    return ans;
}
