#ifndef DATA_H
#define DATA_H

#include <QMainWindow>
#include <iostream>

using namespace std;

class Data
{
public:
    Data();
    qint64 spendtime;
    string testdata;
    string submit;
    bool correct;
    int score;
    int nowfloor;
    int distance;
    int elevatorpeople;
};

#endif // DATA_H
