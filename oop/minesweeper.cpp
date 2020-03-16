#include "minesweeper.h"
#include <sstream>
#include <vector>

Minesweeper::Minesweeper()
{

}

string Minesweeper::solve(string s)
{
    stringstream ss;
    int r, c;
    char **p1;
    int **p2;
    vector<int> x, y;
    string ans;

    ss<<s;
    ss>>r>>c;

    p1 = new char *[r];
    p2 = new int *[r];
    for(int i = 0; i < r; i++)
    {
        p1[i] = new char[c];
        p2[i] = new int[c]();
        for(int j = 0; j < c; j++)
        {
            ss>>p1[i][j];
            if(p1[i][j]=='*')
            {
                p2[i][j] = -10;
                x.push_back(i);
                y.push_back(j);
            }
        }

    }

    for(int i = 0; i < x.size(); i++)
        for(int m = x[i]-1; m <= x[i]+1; m++)
            for(int n = y[i]-1; n <= y[i]+1; n++)
                if(m>=0&&m<r&&n>=0&&n<c)
                    p2[m][n]++;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(p2[i][j]>=0)
                ans += to_string(p2[i][j]);
            else
                ans += "*";
        }

        ans += " ";

        delete []p1[i];
        delete []p2[i];
    }
    ans.pop_back();
    delete []p1;
    delete []p2;

    return ans;
}
