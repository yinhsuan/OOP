#include "add1.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

Add1::Add1()
{

}

string Add1:: solve(string s)
{
    vector<int> v;
    stringstream ss;
    int n;

    ss<<s;
    while(ss>>n){
        v.push_back(n+1);
    }

    return vectorIntToString(v);
}
