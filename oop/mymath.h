#ifndef MYMATH_H
#define MYMATH_H

#include "problemset.h"
#include <iostream>
#include <vector>

using namespace std;

class MyMath : public ProblemSet
{
public:
    MyMath();
    string solve(string){}
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
    vector<double>stringtoVectorDouble(string);
    string doubleToString(double);
};

#endif // MYMATH_H
