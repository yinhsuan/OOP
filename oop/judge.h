#ifndef JUDGE_H
#define JUDGE_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <iostream>
#include <fstream>

using namespace std;

class Judge
{
public:
    Judge();
    string getData(int question);
    bool submitData(string s);
    qint64 getSpendTime(){return costtime;}
    int getScore() {return score;}

private:
    string ans;
    ifstream in;
    QElapsedTimer timer;
    qint64 costtime;
    int score;
};

#endif // JUDGE_H
