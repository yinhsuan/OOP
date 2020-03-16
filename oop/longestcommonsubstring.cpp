#include "longestcommonsubstring.h"
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <QDebug>

LongestCommonSubstring::LongestCommonSubstring()
{

}

string LongestCommonSubstring::solve(string s)
{
    stringstream ss;
    string s1, s2, ans;
    string::size_type pos;
    bool isAns = false;
    vector<string> v;

    while((pos = s.find_first_of(",.!?")) != string::npos)
        s.erase(pos, 1);

    for(int i = 0; i < s.length(); i++)
        s[i] = (islower(s[i])? toupper(s[i]) : s[i]);

    ss<<s;
    ss>>s1>>s2;

    for(int i = s1.length(); i >= 1; i--)
    {
        for(int j = 0; j <= s1.length()-i; j++)
        {
            if(s2.find(s1.substr(j, i)) != string::npos)
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
