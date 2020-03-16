#ifndef MYTREE_H
#define MYTREE_H

#include "problemset.h"
#include <iostream>
#include <vector>

using namespace std;

class MyTree : public ProblemSet
{
public:
    MyTree();
    string solve(string){}
    vector<double>stringtoVectorDouble(string);
    struct node {
        struct node *left; //left child node
        struct node *right; //right child node
        string keyStr;
        int keyInt;
    };
};

#endif // MYTREE_H
