#include "mymath.h"
#include <sstream>
#include <string>
#include <iomanip>

MyMath::MyMath()
{

}

vector<int> MyMath:: stringtoVectorInt(string s)
{
    vector<int> v;
    stringstream ss;
    int n;

    ss<<s;
    while(ss>>n){
        v.push_back(n);
    }

    return v;
}

string MyMath:: vectorIntToString(vector<int> v)
{
    string s;

    for(int i=0; i<v.size(); i++)
        s += to_string(v[i]) + " ";
    s.pop_back();

    return s;
}

vector<double> MyMath::stringtoVectorDouble(string s)
{
    vector<double> v;
    stringstream ss;
    double n;

    ss<<s;
    while(ss>>n){
        v.push_back(n);
    }

    return v;
}

string MyMath:: doubleToString(double x)
{
    stringstream ss;

    ss<<fixed<<setprecision(2)<<x;
    return ss.str();
}
