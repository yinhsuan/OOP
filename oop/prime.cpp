#include "prime.h"
#include <vector>
#include <cmath>

Prime::Prime()
{

}

string Prime::solve(string s)
{
    vector<int> v(stringtoVectorInt(s));
    vector<int> p;
    int t, i, j, n, m;
    bool isP;

    //跳過2和3的倍數
    for(int k = 0; k < v.size(); k++)
    {
        if(v[k]==2||v[k]==3)
            continue;

        i=(v[k]&1)?v[k]:v[k]-1;

        switch(i%6)
        {
        case 1:
            n = 2;
            break;
        case 3:
            i-=2;
            n = 2;
            break;
        case 5:
            n = 4;
            break;
        }

        while(1)
        {
            t = sqrt(i);
            isP=true;
            for(j=5,m=4;j<=t;j+=m)
            {
                if(i%j==0)
                {
                    isP=false;
                    break;
                }
                m^=6;
            }
            if(isP)
            {
                v[k]=i;
                break;
            }

            i-=n;
            n^=6; // 2 <-> 4
        }
    }

    return vectorIntToString(v);
}
