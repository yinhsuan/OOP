#include "longestshortestdistance.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <QDebug>

LongestShortestDistance::LongestShortestDistance()
{

}

string LongestShortestDistance::solve(string s)
{
    stringstream ss;
    string ans;
    int n, a, b;
    string al;

    ss<<s;
    ss>>n>>a>>b>>al;

    al = (al=="al"? "ASC" : "DESC");

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

    query.exec("SELECT ROUND(MAX(dis), 4), ROUND(MIN(dis), 4) FROM "
               "(SELECT SQRT(POW(x1-x2, 2)+POW(y1-y2, 2)) AS dis FROM "
               "(SELECT ROUND(LAT, "+QString::number(n)+") AS x1, ROUND(LON, "+QString::number(n)+") AS y1 FROM citytable "
               "GROUP BY x1, y1 "
               "ORDER BY CITY "+QString::fromStdString(al)+", ID ASC "
               "LIMIT "+QString::number(a-1)+", "+QString::number(b-a+1)+") AS a, "
               "(SELECT ROUND(LAT, "+QString::number(n)+") AS x2, ROUND(LON, "+QString::number(n)+") AS y2 FROM citytable "
               "GROUP BY x2, y2 "
               "ORDER BY CITY "+QString::fromStdString(al)+", ID ASC "
               "LIMIT "+QString::number(a-1)+", "+QString::number(b-a+1)+") AS b "
               "WHERE !(x1=x2 AND y1=y2)  AND ((x1<x2) OR (x1=x2 AND y1<y2))) AS c");

    query.next();   
    for(int i = 0; i < 2; i++)
    {
        if(query.isNull(i))
            ans += "NULL ";
        else
        {
            stringstream ss1;
            ss1<<fixed<<setprecision(4)<<query.value(i).toDouble();
            ans += ss1.str() + " ";
        }
    }
    ans.pop_back();

    return ans;
}
