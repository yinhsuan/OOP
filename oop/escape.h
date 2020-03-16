#ifndef ESCAPE_H
#define ESCAPE_H

#include "myother.h"
#include <sstream>

class Escape : public MyOther
{
public:
    Escape();
    string solve(string s);
private:
    int r, c;
    int jx, jy;
    int fx, fy;
    int min;
    int **map;
    bool **mark;
    bool suc;
    void trace(int, int, int, int);
};

#endif // ESCAPE_H
