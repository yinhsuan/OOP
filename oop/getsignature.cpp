#include "getsignature.h"
#include <sstream>
#include <vector>

GetSignature::GetSignature()
{

}

string GetSignature::solve(string s)
{
    //待優化
    stringstream ss;
    int n, t, max = 0, m;
    vector<int> now, next, count, path;
    vector<bool> mark;

    ss<<s;
    ss>>n;

    for(int i = 0; i < n; i++)
    {
        ss>>t;
        now.push_back(t);
        ss>>t;
        next.push_back(t);
        count.push_back(0);
        mark.push_back(false);
    }

    for(int i = 0; i < n; i++)
    {
        t = i;
        for(int j = 0; j < n; j++)
            mark[j] = false;
        while(!mark[t])
        {
            count[i]++;
            mark[t] = true;
            for(int j = 0; j < n; j++)
            {
                if(now[j]==next[t])
                {
                    t = j;
                    break;
                }
            }
        }

        if(count[i] > max)
        {
            max = count[i];
            m = i;
        }
        else if (count[i]==max && now[i]<now[m])
            m = i;
    }

    return to_string(now[m]);
}
