#ifndef MYOTHER_H
#define MYOTHER_H

#include "problemset.h"
#include <iostream>
#include <vector>

using namespace std;

class MyOther : public ProblemSet
{
public:
    MyOther();
    string solve(string){}
    int stringtoInt(string);
};

#endif // MYOTHER_H
