#include "myother.h"
#include <sstream>

MyOther::MyOther()
{

}

int MyOther::stringtoInt(string s)
{
    stringstream ss;
    int n;

    ss<<s;
    ss>>n;

    return n;
}
