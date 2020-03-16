#include "findfactorial.h"
#include <cmath>

FindFactorial::FindFactorial()
{

}

string FindFactorial::solve(string s)
{
    vector<int> v(stringtoVectorInt(s));
    string ans;
    vector<int> prime(1,2), f1(1,1);
    int t, t2, n=2;
    bool isP;


    for(int i = 0; i < v.size(); i++)
    {
        while(f1.back()<v[i])
        {
            n++;
            t = n;
            t2 = 0;
            switch(n%2)
            {
            case 0:
                for(int j = 0; j < prime.size(); j++)
                {
                    while(t%prime[j]==0)
                    {
                        t/=prime[j];
                        t2++;
                    }
                    if(t==1)
                        break;
                }
                f1.push_back(f1.back()+t2);
                break;

            case 1:
                isP = true;
                for(int j = 3; j <= sqrt(n); j+=2)
                {
                    if(n%j==0)
                    {
                        isP = false;
                        break;
                    }
                }
                if(isP)
                    prime.push_back(n);

                for(int j = 1; j < prime.size(); j++)
                {
                    while(t%prime[j]==0)
                    {
                        t/=prime[j];
                        t2++;
                    }
                    if(t==1)
                        break;
                }
                f1.push_back(f1.back()+t2);
                break;
            }

        }
        for(int j = 0; j < f1.size(); j++)
        {
            if(v[i]==f1[j])
            {
                ans+=to_string(j+2)+"! ";
                break;
            }
            if(v[i]<f1[j])
            {
                ans+="N ";
                break;
            }

        }
    }
    ans.pop_back();

    return ans;
}
