#include "building.h"

Building::Building()
{
    connect(&timer,SIGNAL(timeout()) ,this, SLOT(update()));

    judge.show();
    judge.setSeed(0);
    int n=judge.getConditionNum();
    setPerson(n);
    for(int i = 0; i < 27; i++)
    {
        judge.showStatus(i, people, 1);
        judge.showStatus(i, people, 0);
    }
    scheduler.computePath(people);

    floor[0]=new Floor(new ShortestAndLongestPair());
    floor[1]=new Floor(new Minesweeper());
    floor[2]=new Floor(new GetSignature()); //待優化:高
    floor[3]=new Floor(new ShyGame());
    floor[4]=new Floor(new Myfibfib());
    floor[5]=new Floor(new LargestRoot());
    floor[6]=new Floor(new TreeWalk());
    floor[7]=new Floor(new FindFactorial());
    floor[8]=new Floor(new ShortestSummationDistance());
    floor[9]=new Floor(new Add1());
    floor[10]=new Floor(new DistanceBetweenPrime()); //待優化:低
    floor[11]=new Floor(new MarioOjisan()); //待優化:低
    floor[12]=new Floor(new Escape()); //未完成:高
    floor[13]=new Floor(new Subtract1());
    floor[14]=new Floor(new FindPeriodOfString());
    floor[15]=new Floor(new LargeFactorical());
    floor[16]=new Floor(new SumOfLargeHexidecimalInteger());
    floor[17]=new Floor(new LongestCommonSubstring());
    floor[18]=new Floor(new GetSolution()); //未完成:高
    floor[19]=new Floor(new LongestPeekPalindrome());
    floor[20]=new Floor(new Maze());
    floor[21]=new Floor(new EasyCity1());
    floor[22]=new Floor(new ManhattanDistance());
    floor[23]=new Floor(new Median());
    floor[24]=new Floor(new EasyCity2());
    floor[25]=new Floor(new LongestShortestDistance());
    floor[26]=new Floor(new SymmetricPairs());
}

void Building::setPerson(int r)
{
    query.exec("use FINAL");
    query.exec("use initialtable");
    if(r<10)
        query.exec("select * from initialtable where id like '0000" + QString::number(r) + "%'");
    else if(r>=10 && r<=99)
        query.exec("select * from initialtable where id like '000" + QString::number(r) + "%'");
    else if(r>=100&&r<=999)
        query.exec("select * from initialtable where id like '00" + QString::number(r) + "%'");
    else if(r>=1000)
        query.exec("select * from initialtable where id like '0" + QString::number(r) + "%'");

    while(query.next())
    {
        people.id.push_back(query.value(0).toString());
        people.nowfloor.push_back(query.value(1).toInt());
        people.destination.push_back(query.value(2).toInt());
        people.num.push_back(query.value(3).toInt());
    }

    for(int i = 0; i < 27; i++)
        people.arrnum[people.destination[i]-1]=people.num[i];

    for(int i = 0; i < 27; i++)
        judge.question[i] = people.arrnum[i]+people.num[i];
}

void Building::run(int n, int b)
{
    int times;

    data.testdata=judge.getData(n, b, times);

    if (data.testdata != "GIVEUP")
        for(int i=0;i<times;i++)
            data.submit=floor[n]->p->solve(data.testdata);
    else
        data.submit="~";

    data.correct=judge.submitData(data.submit, n);
    data.spendtime=judge.getSpendTime();
    data.distance=judge.getDistance();
}

void Building::startSimulation()
{
    data.elevatorpeople = 0;
    judge.setDistance();
    judge.setCheckBox();
    timer.start(100);
    timer.setSingleShot(true);
}

void Building::update()
{
    data.nowfloor = scheduler.getNowFloor();

    if (data.nowfloor != 0)
    {
        for(int i = 0; i < scheduler.getNowPeople(); i++)
            run(data.nowfloor-1, scheduler.getNowStatus()); //人進出皆要解題

        if(scheduler.getNowStatus()) //人進
        {
            data.elevatorpeople+=scheduler.getNowPeople();
            people.num[data.nowfloor-1]-=scheduler.getNowPeople();
            judge.showStatus(data.nowfloor-1, people, scheduler.getNowStatus());
        }
        else  //人出
        {
            data.elevatorpeople-=scheduler.getNowPeople();
            people.arrnum[data.nowfloor-1]-=scheduler.getNowPeople();
            judge.showStatus(data.nowfloor-1, people, scheduler.getNowStatus());
        }
        timer.start(100);
    }
    else
    {
        timer.stop();
        judge.scheduleEnd();
        scheduler.setIndex(-1);
    }

    emit updateGUI();
}
