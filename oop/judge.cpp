#include "judge.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

Judge::Judge()
{
    score = 0;
}

string Judge::getData(int question)
{
    string filename;
    string t1, t2;
    vector<string> v1, v2;
    int p;

    filename = to_string(question) + ".txt";
    in.open(filename.c_str());
    while(getline(in, t1))
    {
        getline(in, t2);
        v1.push_back(t1);
        v2.push_back(t2);
    }
    in.close();

    p = rand()%v1.size();
    ans = v2[p];

    timer.start();

    return v1[p];
}

bool Judge::submitData(string s)
{
    costtime=timer.nsecsElapsed();

    if(s==ans)
    {
        score += 100;
        return true;
    }
    else
        return false;
}
