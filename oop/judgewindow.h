#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QWidget>
#include <QElapsedTimer>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <cmath>
#include <fstream>
#include <QLineEdit>
#include <QCheckBox>
#include "people.h"

using namespace std;

namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit JudgeWindow(QWidget *parent = nullptr);
    ~JudgeWindow();
    string getData(int floor,int b, int& datatimes);//input 0-26
    void setSeed(int seed){srand(seed);}
    bool submitData(string s, int floor);
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();//return 1-xxxx
    int getDistance(){return distance;}
    void scheduleEnd();
    void setDistance(){lastfloor = distance = 0;}
    void showStatus(int, People, int);
    void setCheckBox();
    qint64 totalcost[27];
    int correct[27];
    int question[27];
    int floordatatimes[27];
    int floornextdata[27];
    unsigned long long score[27];
    QSqlQuery query;
    QLineEdit showline[27][4];
    QLineEdit inputIdName[2][2];
    QCheckBox checkbox[27];
    QString stud_id1, stud_id2;
    QString stud_name1, stud_name2;


private slots:
    void on_exportToDatabase_clicked();

private:
    Ui::JudgeWindow *ui;
    string ans;
    QElapsedTimer timer;
    qint64 costtime;
    int distance;
    int lastfloor;

};

#endif // JUDGEWINDOW_H
