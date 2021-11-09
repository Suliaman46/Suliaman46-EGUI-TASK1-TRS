#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStructure.h"
#include "addentry.h"
#include "addactivity.h"
#include "editentry.h"
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
    ui->comboBox_rowNum->setPlaceholderText("Select Row Num");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_clicked()
//{
////    QString fileName = "/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json";
////    if(QFile::exists(fileName))
////        qDebug() << "File found";
////    else
////        qDebug() << "File not found";
//////    QFile file("/home/suliaman/first/try.json");
////    QFile file("/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json");
////    file.open(QIODevice::ReadOnly | QIODevice::Text);
////    QByteArray jsonData = file.readAll();
////    file.close();

////    QJsonDocument document = QJsonDocument::fromJson(jsonData);
////    QJsonObject object = document.object();

////    if(object.contains("activities"))
////        qDebug() << "activities key exists";
////    else
////        qDebug() << "key does not exist";
//////    QJsonValue value = object.value("activities");
//////    QJsonValue value = object.value("agentsArray");
//////    QJsonArray attributeArray = value.toArray();
////    activities first;
////    first.read(object);

//    user firstuser("kowalski","/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/DATABASE/USERS");
//    firstuser.read();
//    firstuser.write();
//}




void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->comboBox_rowNum->clear();
    sessionUser::getInstance().setDate(date);
    refreshModel();
//    dataModel* myModel = new dataModel(DataBase::getInstance().getUserList());
//    ui->dailyActivitiesTbl->setModel(myModel);
//    int rowNum = myModel->rowCount();
//    if(rowNum > 0)
//    {
//        QStringList forRowNumComboBox;
//        for (int i= 0; i< rowNum ;++i ) {
//            forRowNumComboBox.append(QString::number(i+1));
//        }
//        ui->comboBox_rowNum->addItems(forRowNumComboBox);
//    }
}


void MainWindow::on_saveJsonBtn_clicked()
{
    DataBase::getInstance().write();
}


void MainWindow::on_addActivityBtn_clicked()
{
    addActivity addActivityWindow;
    addActivityWindow.setModal(true);
    addActivityWindow.exec();

}

void MainWindow::on_addEntryBtn_clicked()
{
    addEntry addEntryWindow;
    addEntryWindow.setModal(true);
    addEntryWindow.exec();
    refreshModel();

}

void MainWindow::on_editEntryBtn_clicked()
{
    editEntry editEntryWindow;
    editEntryWindow.setModal(true);
    editEntryWindow.exec();
    refreshModel();
}

void MainWindow::on_comboBox_rowNum_textActivated(const QString &arg1)
{
    sessionUser::getInstance().setRowSelected(arg1.toInt());
}

void MainWindow::refreshModel()
{
    ui->comboBox_rowNum->clear();
    dataModel* myModel = new dataModel(DataBase::getInstance().getUserList());
    myModel->initTable(*ui->dailyActivitiesTbl);
    ui->dailyActivitiesTbl->setModel(myModel);
    int rowNum = myModel->rowCount();
    if(rowNum > 0)
    {
        QStringList forRowNumComboBox;
        for (int i= 0; i< rowNum ;++i ) {
            forRowNumComboBox.append(QString::number(i+1));
        }
        ui->comboBox_rowNum->addItems(forRowNumComboBox);
    }
    sessionUser::getInstance().setRowSelected(0);
}


void MainWindow::on_refreshTblBtn_clicked()
{
    refreshModel();
}


void MainWindow::on_deleteEntryBtn_clicked()
{
    DataBase::getInstance().removeEntry();
    refreshModel();
}

