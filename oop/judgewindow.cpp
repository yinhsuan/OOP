#include "judgewindow.h"
#include "ui_judgewindow.h"

#include <QDebug>

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);

    query.exec("drop database if exists FINAL");
    query.exec("create database if not exists FINAL");
    query.exec("use FINAL");
    query.exec("drop table if exists datatable");
    query.exec("create table datatable (ID varchar(8), Floor int, Question TEXT, Answer TEXT, primary key(ID))");
    query.exec("use datatable");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata_1225.csv' "
                "INTO TABLE datatable "
                "FIELDS TERMINATED BY ',' "
                "ENCLOSED BY '\"' "
                "LINES TERMINATED BY '\r\n' "
                "IGNORE 1 ROWS");

    query.exec("drop table if exists initialtable");
    query.exec("create table initialtable (ID varchar(8), Nowfloor int, Destination int, Number int, primary key(ID))");
    query.exec("use initialtable");
    query.exec("LOAD DATA INFILE 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' "
                "INTO TABLE initialtable "
                "FIELDS TERMINATED BY ',' "
                "ENCLOSED BY '\"' "
                "LINES TERMINATED BY '\r\n' "
                "IGNORE 1 ROWS");

    for(int i = 0; i < 27; i++)
    {
        totalcost[i] = 0;
        correct[i] = 0;
        floornextdata[i] = 0;
        score[i] = 0;
    }

    for(int i = 0; i < 21; i++)
        floordatatimes[i] = 10;
    for(int i = 21; i < 27; i++)
        floordatatimes[i] = 1;

    for(int i = 0; i < 27; i++)
        for(int j = 0; j < 4; j++)
            ui->gridLayout->addWidget(&showline[i][j], i, j);

    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
            ui->gridLayout_2->addWidget(&inputIdName[i][j], i, j);

    for (int i=0; i<27; i++)
        for (int j=0; j<1; j++)
            ui->gridLayout_3->addWidget(&checkbox[i], i, 4);

    checkbox[12].setChecked(true);
}

JudgeWindow::~JudgeWindow()
{
    delete ui;
}

string JudgeWindow::getData(int floor, int b, int& datatimes)
{
    distance+=abs(floor-lastfloor);
    lastfloor = floor;

    if(checkbox[floor].isChecked())
    {
        timer.start();
        return "GIVEUP";
    }

    vector<string> v1, v2;
    int p;

    datatimes = floordatatimes[floor];

    query.exec("use FINAL");
    query.exec("use datatable");
    query.exec("SELECT Question, Answer FROM datatable "
               "WHERE Floor="+QString::number(floor+1));

    while(query.next())
    {
        v1.push_back(query.value(0).toString().toStdString());
        v2.push_back(query.value(1).toString().toStdString());
    }

    p = floornextdata[floor];
    floornextdata[floor]++;
    if(floornextdata[floor]==v1.size())
        floornextdata[floor] = 0;

    ans = v2[p];

    timer.start();

    return v1[p];
}

bool JudgeWindow::submitData(string s, int floor)
{
    costtime=timer.nsecsElapsed();
    costtime /= floordatatimes[floor];

    if(!s.compare(ans))
    {
        totalcost[floor]+=costtime;
        correct[floor]++;
        score[floor] += 10000000000 + (unsigned long long)pow(2, floornextdata[floor]-1);
        return true;
    }
    else
        return false;
}

int JudgeWindow::getConditionNum()
{
    //return rand()%300+1;
    return 1;
}

void JudgeWindow::scheduleEnd()
{
    ofstream outfile;
    outfile.open("time.txt");

    for(int i = 0; i < 27; i++)
        outfile<<i+1<<","<<totalcost[i]<<","<<correct[i]<<","<<question[i]<<endl;

    outfile.close();

    query.exec("use FINAL");
    query.exec("drop table if exists floorscoretable");
    query.exec("create table floorscoretable (stud_id1 char(7), stud_name1 varchar(5), stud_id2 char(7), stud_name2 varchar(5), floor int, timespend bigint, pass int, totalques int, totalscore bigint)");

    for (int i=0; i<27; i++) {
        query.exec("insert into floorscoretable value ('"+stud_id1+"', '"+stud_name1+"', '"+stud_id2+"', '"+stud_name2+"', '"+QString::number(i+1)+"', '"+QString::number(totalcost[i])+"', '"+QString::number(correct[i])+"', '"+QString::number(question[i])+"', '0')");
    }
    query.exec("use FINAL");
    query.exec("drop table if exists totalpathtable");
    query.exec("create table totalpathtable (stud_id1 char(7), stud_name1 varchar(5), stud_id2 char(7), stud_name2 varchar(5), pathlen int)");
    query.exec("insert into totalpathtable value ('"+stud_id1+"', '"+stud_name1+"', '"+stud_id2+"', '"+stud_name2+"', '"+QString::number(distance)+"')");
}

void JudgeWindow::showStatus(int n, People people, int b)
{
    if(b)
        showline[n][0].setText(QString::number(people.num[n]));
    else
        showline[n][1].setText(QString::number(people.arrnum[n]));
    showline[n][2].setText(QString::number(totalcost[n]));
    showline[n][3].setText(QString::number(score[n]));
}

void JudgeWindow::on_exportToDatabase_clicked()
{
    //IP(Hostname): 140.113.146.120
    //Username: aoopstudent
    //Password: tsaimother
    //Databasename: aoopstudentuse

    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("140.113.146.126");
    database.setDatabaseName("aoopstudentuse"); // schema name
    database.setUserName("aoopstudent");
    database.setPassword("tsaimother"); // your password
    database.setPort(3306);
    bool ok = database.open();

    if(ok)
        qDebug()<<"Judge Successful Connection.";
    else
        qDebug()<<"Judge Error: Cannot connect!!!";


    stud_id1 = inputIdName[0][0].text();
    stud_id2 = inputIdName[1][0].text();
    stud_name1 = inputIdName[0][1].text();
    stud_name2 = inputIdName[1][1].text();

    QSqlQuery query1;
    query1.exec("use aoopstudentuse");
    for (int i=0; i<27; i++)
        query1.exec("insert into floorscore value ('"+stud_id1+"', '"+stud_name1+"', '"+stud_id2+"', '"+stud_name2+"', '"+QString::number(i+1)+"', '"+QString::number(totalcost[i])+"', '"+QString::number(correct[i])+"', '"+QString::number(question[i])+"', '"+QString::number(score[i])+"')");
    query1.exec("insert into totalpath value ('"+stud_id1+"', '"+stud_name1+"', '"+stud_id2+"', '"+stud_name2+"', '"+QString::number(distance)+"')");
}

void JudgeWindow::setCheckBox()
{
    for(int i=0;i<27;i++)
        checkbox[i].setDisabled(true);
}
