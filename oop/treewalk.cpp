#include "treewalk.h"
#include <sstream>

TreeWalk::TreeWalk()
{

}

string TreeWalk::solve(string s)
{
    vector<char> v1, v2, v3;
    bool *mark;
    string s1, s2, ans;
    stringstream ss;
    int size, t1, t2;

    ss<<s;
    ss>>s1>>s2;

    size = s1.size();

    for(int i = 0; i < size; i++)
    {
        v1.push_back(s1[i]);
        v2.push_back(s2[i]);
    }
    mark = new bool[size]();

    v3.push_back(v1[0]);
    for(int i = 0; i < size; i++)
    {
        if(v2[i]==v1[0])
        {
            mark[i] = true;
            break;
        }
    }

    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(v1[i]==v2[j])
            {
                mark[j] = true;
                t1 = t2 = -1;
                for(int k = j-1; k >= 0; k--)
                {
                    if(mark[k])
                    {
                        t1 = k;
                        break;
                    }
                }
                for(int k = j+1; k < size; k++)
                {
                    if(mark[k])
                    {
                        t2 = k;
                        break;
                    }
                }

                if(t2==-1)
                {
                    for(int k = 0; k < size; k++)
                    {
                        if(v3[k]==v2[t1])
                        {
                            v3.insert(v3.begin()+k, v1[i]);
                            break;
                        }
                    }
                }
                else if(t1==-1)
                {
                    for(int k = 0; k < v3.size(); k++)
                    {
                        if(v3[k]==v2[t2])
                        {
                            v3.insert(v3.begin()+k, v1[i]);
                            break;
                        }
                    }
                }
                else
                {
                    for(int k = 0; k < v3.size(); k++)
                    {
                        if(v3[k]==v2[t1] || v3[k]==v2[t2])
                        {
                            v3.insert(v3.begin()+k, v1[i]);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }

    for(int i = 0; i < size; i++)
        ans += v3[i];

    delete []mark;

    return ans;
}
