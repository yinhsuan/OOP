#include "shygame.h"
#include <sstream>
#include <queue>
#include <vector>
#include <QDebug>

ShyGame::ShyGame()
{

}

string ShyGame::solve(string s)
{
    /*
//    vector<int> v = stringtoVectorInt(s);
//    vector<int> ans;
//    int tmp;

    //q.push(x); 将x接到队列的末端
    //q.pop(); 弹出队列的第一个元素
    for (int i=1; i<v.size(); i++) {
        queue<int> q;
        for (int j=0; j<v[0]; j++) {
            q.push(j+1);
        }
        while (q.size() > 1) {
            for (int j=0; j<v[i]-1; j++) {
                tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            q.pop();
        }
        tmp = q.front();
        ans.push_back(tmp);
        qDebug()<<tmp;
    }
    return vectorIntToString(ans);

//    vector<int> v = stringtoVectorInt(s), ans, q;
//    int tmp = 0;

//    for(int i=1; i<v.size(); ++i) { // m == v[i]
//            tmp = 0;
//            for(int j = 1; j < v[i]; ++j) {
//                tmp = (tmp+v[i])%j;
//            }
//            ans.push_back(tmp);
//            qDebug()<<tmp;

//    }
*/
    vector<int> v = stringtoVectorInt(s), ans, q;
    int t;
    for(int i = 1; i < v.size(); i++)
    {
        q.clear();
        for(int j = 1; j <= v[0]; j++)
            q.push_back(j);
        t = 0;
        for(int j = 0; j < v[0]-1; j++)
        {
            t = (v[i]+t)%(v[0]-j);
            if(t==0)
                t = q.size();
            t--;
            q.erase(q.begin()+t);
        }
        ans.push_back(q[0]);
    }

    return vectorIntToString(ans);
}
