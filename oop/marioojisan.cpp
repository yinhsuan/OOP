#include "marioojisan.h"
#include <sstream>

MarioOjisan::MarioOjisan()
{

}

string MarioOjisan::solve(string s)
{
    stringstream ss;
    int sum, n, count, t, t1;
    string ans;

    ss<<s;
    while(ss>>n)
    {
        ss>>t;
        sum = t1 = t;
        count = 1;

        for(int i = 1; i < n; i++)
        {
            ss>>t;
            if(sum<t)
            {
                count++;
                t1 = sum;
            }
            sum = t1 + t;
        }
        ans += to_string(count) + " ";
    }
    ans.pop_back();

    return ans;
}
