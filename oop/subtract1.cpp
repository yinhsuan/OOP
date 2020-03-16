#include "subtract1.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

Subtract1::Subtract1()
{

}

string Subtract1:: solve(string s)
{
    vector<int> v;
    stringstream ss;
    int n;

    ss<<s;
    while(ss>>n){
        v.push_back(n-1);
    }

    return vectorIntToString(v);
}
