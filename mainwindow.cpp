#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStructure.h"
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QDir>
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
    QString fileName = "/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json";
    if(QFile::exists(fileName))
        qDebug() << "File found";
    else
        qDebug() << "File not found";
//    QFile file("/home/suliaman/first/try.json");
    QFile file("/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/activity.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();

    if(object.contains("activities"))
        qDebug() << "activities key exists";
    else
        qDebug() << "key does not exist";
//    QJsonValue value = object.value("activities");
//    QJsonValue value = object.value("agentsArray");
//    QJsonArray attributeArray = value.toArray();
    activities first;
    first.read(object);


}

