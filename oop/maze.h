#ifndef MAZE_H
#define MAZE_H

#include "myother.h"
#include <stack>

class Point
{
public:
    Point(int a, int b){setxy(a,b);}
    Point(){}
    void setxy(int a, int b){x=a;y=b;}
    int getX(){return x;}
    int getY(){return y;}
private:
    int x;
    int y;
};

class Maze : public MyOther
{
public:
    Maze();
    string solve(string s);
    void trace(stack<Point>, int, int);
private:
    char **path;
    bool **mark;
    int r, c;
    int sx, sy, ex, ey;
    bool suc;
    string ans;
};

#endif // MAZE_H
