#ifndef GETSOLUTION_H
#define GETSOLUTION_H

#include "mymath.h"

class GetSolution : public MyMath
{
public:
    GetSolution();
    void setMatrix(int row,int column, vector<double> coefficient);
    vector<double> Solution(vector<double> b);
    string solve(string s);
private:
    int row;
    int column;
    vector<double> coefficient;
};

#endif // GETSOLUTION_H
