#include "sumoflargehexidecimalinteger.h"
#include <sstream>

SumOfLargeHexidecimalInteger::SumOfLargeHexidecimalInteger()
{

}

string SumOfLargeHexidecimalInteger::solve(string s) {
    stringstream ss;
    string s1, ans;
    vector<string> v;
    string::size_type size = 0;
    int t, num, carry;

    ss<<s;

    while(ss>>s1 && s1!="0")
    {
        v.push_back(s1);
        if(s1.size()>size) // size:找出最長字串的大小
            size = s1.size();
    }

    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++)
            v[i][j] += ((v[i][j]&64)? (10-'a') : (-'0'));

    for(int i = 0; i < v.size(); i++)
    {
        t = size-v[i].size();
        for(int j = 0; j < t; j++)
            v[i]='\0'+v[i];
    }

    carry = 0;
    for(int i = size; i >= 0; i--)
    {
        num = carry;
        for(int j = 0; j < v.size(); j++)
            num+=v[j][i];
        carry = num>>4; //carry = num/16;
        ans = (char)(num&15)+ans; //ans = (char)(num%16)+ans;

    }

    while(carry)
    {
        ans = static_cast<char>(carry&15)+ans;
        carry>>=4;
    }

    ans.pop_back();  //去掉原本字串的'\0'

    for(string::size_type i = 0; i < ans.size(); i++)
    {
        if(ans[i]<10)
            ans[i]+='0';
        else
            ans[i]+=('a'-10);
    }

    return ans;
}
