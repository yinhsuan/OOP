#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "building.h"
#include "data.h"
#include <stdlib.h>
#include <time.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    connect(&building,SIGNAL(updateGUI()),this, SLOT(slot_update_data()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    building.run(ui->comboBox->currentIndex(), 1);
    windata=building.getData();

    ui->testdata->setText(QString::fromStdString(windata.testdata));
    ui->submit->setText(QString::fromStdString(windata.submit));
    ui->spendtime->setText(QString::number(windata.spendtime));
    ui->correct->setText(QString::number(windata.correct));
}

void MainWindow::on_pushButton_2_clicked()
{
    people = building.getPeople();
    ui->peoplenumber->setText(QString::number(people.getNumber(ui->comboBox->currentIndex())));
    ui->destination->setText(QString::number(people.getDestination(ui->comboBox->currentIndex())));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_8->clear();
    building.startSimulation();
}

void MainWindow::slot_update_data()
{
    windata=building.getData();

    if (windata.nowfloor != 0)
    {
        ui->comboBox->setCurrentText(QString::number(windata.nowfloor));
        ui->testdata->setText(QString::fromStdString(windata.testdata));
        ui->submit->setText(QString::fromStdString(windata.submit));
        ui->spendtime->setText(QString::number(windata.spendtime));
        ui->correct->setText(QString::number(windata.correct));
        ui->lcdNumber->display(windata.nowfloor);
        ui->lcdNumber_2->display(windata.elevatorpeople);
        ui->lcdNumber_3->display(windata.distance);
    }
    else
        ui->label_8->setText(QString::fromStdString("Finish!!"));
}
