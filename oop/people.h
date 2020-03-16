#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <vector>
#include <string>
#include <QString>
#include <QSqlQuery>
#include <QApplication>
#include <QSqlDatabase>

using namespace std;

class People
{
public:
    People();
    vector<QString> id;
    vector<int> nowfloor;
    vector<int> destination;
    vector<int> num;
    int arrnum[27];
    int getNumber(int);
    int getDestination(int);
};

#endif // PEOPLE_H
