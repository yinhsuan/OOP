#include "longestpeekpalindrome.h"
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <QDebug>

LongestPeekPalindrome::LongestPeekPalindrome()
{

}

string LongestPeekPalindrome::solve(string s)
{
    stringstream ss;
    string s1, ans;
    string::size_type pos;
    bool isAns = false;
    vector<string> v;

    while((pos = s.find_first_of(",.!?")) != string::npos)
        s.erase(pos, 1);

    for(int i = 0; i < s.length(); i++)
        s[i] = (islower(s[i])? toupper(s[i]) : s[i]);

    ss<<s;
    ss>>s1;

    for(int i = s1.length(); i >= 1; i--)
    {
        for(int j = 0; j <= s1.length()-i; j++)
        {
            string s2;
            for(int k = 0; k < i ; k++)
                s2=s1[k+j]+s2;

            if(s1.substr(j, i)==s2)
            {
                isAns = true;
                v.push_back(s1.substr(j, i));
            }
        }

        if(isAns)
        {
            ans = v[0];
            for(int i = 1; i < v.size(); i++)
                if(v[i]<ans)
                    ans = v[i];
            break;
        }
    }

    return ans;
}
