#include "symmetricpairs.h"
#include <QSqlQuery>
#include <sstream>
#include <string>
#include <iomanip>
#include <QDebug>

SymmetricPairs::SymmetricPairs()
{

}

string SymmetricPairs::solve(string s)
{
    stringstream ss;
    string ans;
    int m, n, k, t;
    string ev;

    ss<<s;
    ss>>ev>>m>>n>>k;

    t = (ev=="od"? 1 : 0);

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

    query.exec("UPDATE CITYTABLE AS a, CITYTABLE AS b "
               "SET a.LON = b.LAT, b.LAT = a.LON "
               "WHERE a.ID%2="+QString::number(t)+" AND b.ID%2="+QString::number(t)+" AND a.ID=b.ID");

    query.exec("UPDATE CITYTABLE "
               "SET LAT=LON "
               "WHERE ID LIKE '%"+QString::number(m)+"'");

    query.exec("SELECT X1 AS X, Y1 AS Y FROM "
               "(SELECT * FROM "
               "((SELECT ID AS ID1, ROUND(LAT, "+QString::number(n)+") AS X1, ROUND(LON, "+QString::number(n)+") AS Y1 FROM CITYTABLE "
               "ORDER BY X1 ASC, Y1 ASC) AS a, "
               "(SELECT ID AS ID2, ROUND(LAT, "+QString::number(n)+") AS X2, ROUND(LON, "+QString::number(n)+") AS Y2 FROM CITYTABLE "
               "ORDER BY X2 ASC, Y2 ASC) AS b) "
               "WHERE a.ID1!=b.ID2 AND a.X1=b.Y2 AND a.Y1=b.X2 "
               "AND((a.X1<a.Y1 AND b.X2>b.Y2) OR (a.X1=a.Y1 AND a.ID1<b.ID2)) "
               "GROUP BY a.ID1 "
               "ORDER BY a.X1 ASC, a.Y1 ASC, b.X2 ASC, b.Y2 ASC, a.ID1 ASC, b.ID2 ASC) AS c "
               "GROUP BY ID2 "
               "LIMIT "+QString::number(k-1)+", 1");

    query.next();
    for(int i = 0; i < 2; i++)
    {
        if(query.isNull(i))
            ans += "NULL ";
        else
        {
            stringstream ss1;
            ss1<<fixed<<setprecision(n)<<query.value(i).toDouble();
            ans += ss1.str() + " ";
        }
    }
    ans.pop_back();

    return ans;
}
