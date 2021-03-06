#include "maze.h"
#include <sstream>
#include <QDebug>

Maze::Maze()
{

}

string Maze::solve(string s)
{
    stack<Point> map;
    stringstream ss;

    ans.clear();
    ss<<s;
    ss>>c>>r;

    path = new char *[r];
    mark = new bool *[r];
    for(int i = 0; i < r; i++)
    {
        path[i] = new char[c];
        mark[i] = new bool[c];
    }

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            ss >> path[i][j];
            mark[i][j] = false;

            if(path[i][j]=='S')
            {
                sx = i;
                sy = j;
            }
            if(path[i][j]=='E')
            {
                ex = i;
                ey = j;
            }
        }
    }

    suc = false;
    trace(map, sx, sy);

    for(int i = 0; i < r; i++)
    {
        delete []path[i];
        delete []mark[i];
    }
    delete []path;
    delete []mark;

    ans.pop_back();

    return ans;
}

void Maze::trace(stack<Point> map, int x, int y)
{
    mark[x][y] = true;
    map.push(Point(x, y));

    if(x==ex && y==ey)
    {
        map.pop();
        while(map.size()>1)
        {
            path[map.top().getX()][map.top().getY()] = '1';
            map.pop();
        }

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ans += path[i][j];
                ans += " ";
            }
        }
        suc = true;

        return;
    }
    else
    {
        /*
        //左下右上
        if(!suc && !mark[x][y-1] && path[x][y-1]!='2') trace(map, x, y-1);
        if(!suc && !mark[x+1][y] && path[x+1][y]!='2') trace(map, x+1, y);
        if(!suc && !mark[x][y+1] && path[x][y+1]!='2') trace(map, x, y+1);
        if(!suc && !mark[x-1][y] && path[x-1][y]!='2') trace(map, x-1, y);
        */

        //右下左上
        if(!suc && !mark[x][y+1] && path[x][y+1]!='2') trace(map, x, y+1);
        if(!suc && !mark[x+1][y] && path[x+1][y]!='2') trace(map, x+1, y);
        if(!suc && !mark[x][y-1] && path[x][y-1]!='2') trace(map, x, y-1);
        if(!suc && !mark[x-1][y] && path[x-1][y]!='2') trace(map, x-1, y);

    }

    map.pop();
}
