#include "myfibfib.h"

Myfibfib::Myfibfib()
{

}

string Myfibfib::solve(string s)
{
    vector<int> v(stringtoVectorInt(s)), ans;
    vector<int> fib1(2, 0), fib2(2, 0);
    int t, fib1size, fib2size;

    fib1[1] = fib2[1] = 1;

    //找費氏數列 mod 10的循環
    t = 1;
    while(!(t==1 && fib1.back()==0))
    {
        fib1.push_back(t);
        t = (fib1[fib1.size()-1] + fib1[fib1.size()-2])%10;
    }
    fib1.pop_back();
    fib1size = fib1.size();  //fib1size = 60 (費氏數列 mod 10 , 每"60"個循環一次)

    //找費氏數列 mod 60的循環 (費氏數列 mod 10, 每"60"個循環一次)
    t = 1;
    while(!(t==1 && fib2.back()==0))
    {
        fib2.push_back(t);
        t = (fib2[fib2.size()-1] + fib2[fib2.size()-2])%60;
    }
    fib2.pop_back();
    fib2size = fib2.size();  //fib2size = 120 (費氏數列 mod 60 , 每"120"個循環一次)

    for(int i = 0; i < v.size(); i++)
        ans.push_back(fib1[fib2[v[i]%fib2size]]);

    return vectorIntToString(ans);
}
