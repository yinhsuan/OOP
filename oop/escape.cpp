#include "escape.h"

Escape::Escape()
{

}

string Escape::solve(string s)
{
    /*
    stringstream ss;
    string ans;
    char t;

    ss<<s;
    ss>>r>>c;

    map = new int *[r];
    mark = new bool *[r];
    for(int i = 0; i < r; i++)
    {
        map[i] = new int[c];
        mark[i] = new bool[c]();
        for(int j = 0; j < c; j++)
        {
            ss>>t;
            if(t=='#')
            {
                map[i][j] = 3;
            }
            else if(t=='.')
            {
                map[i][j] = 0;
            }
            else if(t=='J')
            {
                map[i][j] = 1;
                jx = i;
                jy = j;
            }
            else if(t=='F')
            {
                map[i][j] = 2;
                fx = i;
                fy = j;
            }
        }
    }

    min = 0;
    suc = false;
    trace(jx, jy, fx, fy);
    if(suc)
        ans = to_string(min);
    else
        ans = "N";

    for(int i = 0; i < r; i++)
    {
        delete []map[i];
        delete []mark[i];
    }

    delete []map;
    delete []mark;

    return ans;
    */
    string ans;

    return ans;
}

void Escape::trace(int x1, int y1, int x2, int y2)
{

}
