#ifndef SHORTESTSUMMATIONDISTANCE_H
#define SHORTESTSUMMATIONDISTANCE_H

#include "mymath.h"

class ShortestSummationDistance : public MyMath
{
public:
    ShortestSummationDistance();
    string solve(string s);
private:
    vector<int> x, y;
    int n, t;
    vector<int> com, maxc, per, temp1;
    double min;
    void combination();
    void permutation(int);
    void getRemain();
};

#endif // SHORTESTSUMMATIONDISTANCE_H
