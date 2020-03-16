#include "mytree.h"
#include <sstream>
#include <string>
#include <iomanip>

MyTree::MyTree()
{

}

vector<double> MyTree::stringtoVectorDouble(string s)
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
