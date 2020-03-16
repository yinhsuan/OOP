#include "scheduler.h"
#include <QDebug>
Scheduler::Scheduler()
{
    index = -1;
    elevatorpeople = 0;
}

void Scheduler::computePath(People people)
{
    int n[27], d[27], a[27];
    bool dir[27]={false}; //當前樓層的人要往上(true)或往下(false)
    bool isUp=true; //電梯當前往上(true)或往下(false)的狀態
    int upper=26, lower=0; //電梯移動的上下界
    int now=0; //電梯當前樓層
    vector<int> bottom; //電梯裡面的人要到的樓層
    vector<int> amount; //電梯裡面的人要到某樓的數量
    int tem;
    bool isEnd = false;

    for(int i = 0; i < 27; i++)
    {
        n[i] = people.num[i];
        d[i] = people.destination[i];
        a[i] = people.arrnum[i];

        if(i<d[i]) //destination大於當前樓層，代表要往上
            dir[i]=true;
    }

    while(!isEnd)
    {
        //出電梯
        for(int i = 0; i < bottom.size(); i++)
        {
            if(now==bottom[i])
            {
                nowFloor.push_back(now+1);
                nowPeople.push_back(amount[i]);
                nowStatus.push_back(false);
                elevatorpeople-=amount[i];
                a[now]-=amount[i];
                bottom.erase(bottom.begin()+i);
                amount.erase(amount.begin()+i);
                break;
            }
        }

        //進電梯
        if(isUp==dir[now] && elevatorpeople<10 &&n[now])
        {
            nowFloor.push_back(now+1);
            bottom.push_back(d[now]-1);
            tem = elevatorpeople;
            while(n[now]&&elevatorpeople<10)
            {
                n[now]--;
                elevatorpeople++;
            }
            amount.push_back(elevatorpeople-tem);
            nowPeople.push_back(elevatorpeople-tem);
            nowStatus.push_back(true);
        }

        now += (isUp? 1 : -1); //電梯上一層或下一層樓

        //判斷電梯是否到達邊界
        if(isUp && now>upper)
        {
            isUp=false;
            now--;
        }
        else if(!isUp && now<lower)
        {
            isUp=true;
            now++;
        }

        isEnd = true;
        for(int i = 0; i < 27; i++)
        {
            if(a[i])
            {
                isEnd = false;
                break;
            }
        }
    }


    /*
    //舊版
    for(int i = 0; i < 27; i++)
    {
        while(n[i])
        {
            //in
            nowFloor.push_back(i+1);
            if(n[i]>10)
            {
                n[i]-=10;
                elevatorpeople=10;
            }
            else
            {
                elevatorpeople+=n[i];
                n[i]=0;
            }
            nowPeople.push_back(elevatorpeople);
            nowStatus.push_back(1);

            //out
            nowFloor.push_back(d[i]);
            a[i]-=elevatorpeople;
            nowPeople.push_back(elevatorpeople);
            nowStatus.push_back(0);
            elevatorpeople=0;
        }
    }
    */

    nowFloor.push_back(0);
    nowPeople.push_back(0);
    nowStatus.push_back(false);

    ofstream outfile;
    outfile.open("Schedule.txt");

    for(int i = 0; i < nowFloor.size(); i++)
    {
        outfile<<nowFloor[i]<<",";
        if(nowStatus[i])
            outfile<<"I,";
        else
            outfile<<"O,";
        outfile<<nowPeople[i]<<endl;
    }

    outfile.close();


}
