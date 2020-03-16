#include "largestroot.h"
#include <sstream>
#include <iomanip>
#include <QDebug>

LargestRoot::LargestRoot()
{

}

string LargestRoot::solve(string s)
{
    vector<double> v(stringtoVectorDouble(s));
    double node[15];
    int n;
    double max;
    string ans;
    stringstream ss;
    double t;
    string s1;

    for(int i = 0; i < 15; i++)
        node[i] = v[i];

    max = v[14];
    n = 14;

    for(int i = 3; i < 7; i++)
    {
        node[i] += (node[i*2+1] + node[i*2+2]) / 2;
        if(node[i]>max)
        {
            max = node[i];
            n = i;
        }
    }


    for(int i = 1; i < 3; i++)
    {
        node[i] += (node[i*2+1] + node[i*2+2]) / 2;
        if(node[i]>max)
        {
            max = node[i];
            n = i;
        }
    }


    node[0] += (node[1] + node[2]) / 2;
    if(node[0]>max)
    {
        max = node[0];
        n = 0;
    }


    for(int i = 7; i < 14; i++)
    {
        if(node[i] > max)
        {
            max = node[i];
            n = i;
        }
    }
    n++;

    ans += to_string(n) + ":";

    ss<<fixed<<setprecision(3)<<max;
    ss>>t;
    s1 = to_string(t);
    s1.erase(s1.size()-3);

    ans += s1;

    return ans;
}
