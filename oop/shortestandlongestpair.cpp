#include "shortestandlongestpair.h"
#include <cmath>

ShortestAndLongestPair::ShortestAndLongestPair()
{

}

string ShortestAndLongestPair::solve(string s)
{
    vector<double> v(stringtoVectorDouble(s));
    double t;
    double min = INT_MAX, max = INT_MIN;

    for(int i = 0; i < v.size()-5; i+=3)
    {
        for(int j = i+3; j < v.size()-2; j+=3)
        {
            t = (v[i]-v[j])*(v[i]-v[j]) + (v[i+1]-v[j+1])*(v[i+1]-v[j+1]) + (v[i+2]-v[j+2])*(v[i+2]-v[j+2]);
            if(t < min)
                min = t;
            if(t > max)
                max = t;
        }
    }

    return doubleToString(sqrt(min)) + " " + doubleToString(sqrt(max));
}
