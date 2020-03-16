#ifndef BUILDING_H
#define BUILDING_H

#include "data.h"
#include "floor.h"
#include "people.h"
#include "scheduler.h"
#include "judgewindow.h"

#include "shortestandlongestpair.h"
#include "minesweeper.h"
#include "getsignature.h"
#include "shygame.h"
#include "myfibfib.h"
#include "largestroot.h"
#include "treewalk.h"
#include "findfactorial.h"
#include "shortestsummationdistance.h"
#include "add1.h"
#include "distancebetweenprime.h"
#include "marioojisan.h"
#include "escape.h"
#include "subtract1.h"
#include "findperiodofstring.h"
#include "largefactorical.h"
#include "sumoflargehexidecimalinteger.h"
#include "longestcommonsubstring.h"
#include "getsolution.h"
#include "longestpeekpalindrome.h"
#include "maze.h"
#include "easycity1.h"
#include "manhattandistance.h"
#include "median.h"
#include "easycity2.h"
#include "longestshortestdistance.h"
#include "symmetricpairs.h"

#include <QTimer>
#include <QMainWindow>
#include <QObject>
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <time.h>

class Building : public QObject
{
    Q_OBJECT

public:
    Building();
    void run(int, int);
    void setPerson(int);
    Data getData(){return data;}
    People getPeople(){return people;}
    void startSimulation();

signals:
    void updateGUI();

private:
    JudgeWindow judge;
    Data data;
    People people;
    QTimer timer;
    Scheduler scheduler;
    Floor* floor[27];   
    QSqlQuery query;

private slots:
    void update();
};

#endif // BUILDING_H
