#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <fstream>
#include "people.h"
using namespace std;

class Scheduler
{
public:
    Scheduler();
    int getNowFloor(){return nowFloor[++index];}
    int getNowPeople(){return nowPeople[index];}
    int getNowStatus(){return nowStatus[index];}
    void setIndex(int i) {index = i;}
    void computePath(People);
private:
    vector<int> nowFloor;
    vector<int> nowPeople;
    vector<int> nowStatus;
    int index; // temp
    int elevatorpeople;
};

#endif // SCHEDULER_H
