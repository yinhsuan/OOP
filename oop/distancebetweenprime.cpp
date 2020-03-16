#include "distancebetweenprime.h"
#include <cmath>

DistanceBetweenPrime::DistanceBetweenPrime()
{

}

string DistanceBetweenPrime::solve(string s)
{
    vector<int> v(stringtoVectorInt(s)), ans;
    int t, i1, i2, j, m, t1, t2;
    bool isP;


    for(int k=0; k<v.size();k++)
    {
        if(v[k]==2)
        {
            ans.push_back(0);
            continue;
        }
        i1 = i2 = v[k];
        if(!(v[k]&1))
        {
            i1--;
            i2++;
        }

        while(1)
        {
            t = sqrt(i2);
            isP=true;
            for(j=3,m=4;j<=t;j+=2)
            {
                if(i2%j==0)
                {
                    isP=false;
                    break;
                }
            }
            if(isP)
            {
                t2=i2;
                break;
            }

            i2+=2;
        }

        if(t2==v[k])
        {
            ans.push_back(0);
            continue;
        }

        while(1)
        {
            t = sqrt(i1);
            isP=true;
            for(j=3,m=4;j<=t;j+=2)
            {
                if(i1%j==0)
                {
                    isP=false;
                    break;
                }
            }
            if(isP)
            {
                t1=i1;
                break;
            }

            i1-=2;
        }

        ans.push_back(t2-t1);
    }

    return vectorIntToString(ans);
}
