#include "shortestsummationdistance.h"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <QDebug>

using namespace std;

ShortestSummationDistance::ShortestSummationDistance()
{

}

string ShortestSummationDistance::solve(string s)
{
    stringstream ss;
    string ans;

    ss<<s;
    while(ss>>n)
    {
        stringstream ss1, ss2;
        int tem;
        double tem2;

        x.clear();
        y.clear();
        for(int i = 0; i < 2 * n; i++)
        {
            ss>>tem;
            x.push_back(tem);
            ss>>tem;
            y.push_back(tem);
        }

        com.resize(n);
        maxc.resize(n);
        per.resize(2*n);
        temp1.resize(n);

        for(int i = 0; i < n; i++)
        {
            com[i] = i;
            maxc[i] = i*2;
        }
        min = INT_MAX;

        combination();

        ss1<<to_string(min);
        ss1>>tem2;
        ss2<<fixed<<setprecision(2)<<tem2;
        ans += ss2.str() + " ";
    }
    ans.pop_back();

    return ans;
}

void ShortestSummationDistance::combination()
{
    getRemain();

    for(int i = n-1; i >= 0; i--)
    {
        if(com[i] < maxc[i])
        {
            com[i]++;

            for(int j = i+1; j < n; j++)
                com[j] = com[j-1] + 1;

            combination();
        }
    }
}

void ShortestSummationDistance::getRemain()
{
    int t1 = 1, t2 = 0;
    t = 2*n-1;
    for(int i = 1; i < t; i++)
    {
        if(com[t1]==i)
            t1++;
        else
            per[t2++]=i;
    }
    per[t2] = t;

    permutation(n-1);
}

void ShortestSummationDistance::permutation(int k)
{
    double sum;

    if(k > 0)
    {
        for(int i = k; i >= 0; i--)
        {
            if(com[k] > per[i])
                return;

            t = per[k];
            per[k] = per[i];
            per[i] = t;

            permutation(k-1);

            t = per[k];
            per[k] = per[i];
            per[i] = t;
        }
    }
    else
    {
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += sqrt((x[com[i]]-x[per[i]])*(x[com[i]]-x[per[i]]) + (y[com[i]]-y[per[i]])*(y[com[i]]-y[per[i]]));

        if(sum < min)
            min = sum;
    }
}
