#include "largefactorical.h"
#include "cmath"
#include <QDebug>
#include <sstream>

LargeFactorical::LargeFactorical()
{

}


string LargeFactorical::solve(string s) {
    stringstream ss;
        string ans;
        int n, carry, t, num[10] = {0}, flag;
        unsigned long long a = 1, b;
        bool isOverflow = false;

        ss<<s;
        ss>>n;

        //用unsigned long long乘到overflow後, 才用大數*整數, 跟直接大數*整數比稍快一點點
        for(int i = 2; i <= n; i++)
        {
            b = a;
            a *= i;
            if(a/i!=b)
            {
                isOverflow = true;
                ans = to_string(b);
                flag = i;
                break;
            }
        }

        if(!isOverflow)
            return to_string(a);

        for(int i = 0; i < ans.size(); i++)
            ans[i]-='0';

        for(int i = flag; i <= n; i++)
        {
            for(int j = 1; j < 10; j++)
                num[j] = num[j-1] + i; //num[j] = i*j;

            carry = 0;
            for(string::size_type j = ans.size()-1; j != string::npos; j--)
            {
                t = (num[ans[j]] + carry);
                ans[j] = t%10;
                carry = t/10;
            }

            while(carry)
            {
                ans = (char)(carry%10) + ans;
                carry/=10;
            }
        }

        for(int i = 0; i < ans.size(); i++)
            ans[i] += '0';

        return ans;

}
