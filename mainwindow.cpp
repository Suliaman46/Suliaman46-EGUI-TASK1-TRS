#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStructure.h"
#include "addactivity.h"
#include "sessionuser.h"
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QDir>
#include <QTableView>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    QString fileName = "/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json";
//    if(QFile::exists(fileName))
//        qDebug() << "File found";
//    else
//        qDebug() << "File not found";
////    QFile file("/home/suliaman/first/try.json");
//    QFile file("/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json");
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QByteArray jsonData = file.readAll();
//    file.close();

//    QJsonDocument document = QJsonDocument::fromJson(jsonData);
//    QJsonObject object = document.object();

//    if(object.contains("activities"))
//        qDebug() << "activities key exists";
//    else
//        qDebug() << "key does not exist";
////    QJsonValue value = object.value("activities");
////    QJsonValue value = object.value("agentsArray");
////    QJsonArray attributeArray = value.toArray();
//    activities first;
//    first.read(object);

    user firstuser("kowalski","/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/DATABASE/USERS");
    firstuser.read();
    firstuser.write();
}


void MainWindow::on_pushButton_2_clicked()
{
    ADDACTIVITY addActivity;
    addActivity.setModal(true);
    addActivity.exec();
//    sessionUser & SL = sessionUser::getInstance();
//    qDebug() << "username is " + SL.getUserName();

}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    DataBase::getInstance().read();
    sessionUser::getInstance().setDate(date);
    ui->dailyActivitiesTbl->setModel(xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)
    dataModel ;
    tableView.setModel(&myModel);
    tableView.show();


}

