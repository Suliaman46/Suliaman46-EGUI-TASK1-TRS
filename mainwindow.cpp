#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dataStructure.h"
#include "addentry.h"
#include "addactivity.h"
#include "editentry.h"
#include "sessionuser.h"
#include "managermainwindow.h"
#include "managerediting.h"
#include "monthlyactivity.h"
#include <QDebug>
#include <QTableView>
#include <QMessageBox>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Daily Entries Table");
    ui->comboBox_rowNum->setPlaceholderText("Select Row Number");
    ui->comboBox_rowNum->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}


void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->comboBox_rowNum->clear();
    sessionUser::getInstance().setDate(date);
    refreshModel();

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
    if(ui->comboBox_rowNum->currentText().isEmpty())
    {
        QMessageBox::information(this,"No Row Selected","Please select a Row/Change Date before pressing Edit");
    }
    else
    {
        if(!DataBase::getInstance().isMonthFrozen(ui->dateEdit->date().toString("yyyy-MM"),sessionUser::getInstance().getUserName()))
        {
            editEntry editEntryWindow;
            editEntryWindow.setModal(true);
            editEntryWindow.exec();
            refreshModel();
        }
        else
        {
            QMessageBox::information(this,"Month frozen by Manager","Please change Month to Edit Entry");
        }


    }
}

void MainWindow::on_comboBox_rowNum_textActivated(const QString &arg1)
{
    sessionUser::getInstance().setRowSelected(arg1.toInt());
}

void MainWindow::refreshModel()
{
    sessionUser::getInstance().setTotalDailyTime(0);
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
    ui->label_totalTIme->setText(QString::number(sessionUser::getInstance().getTotalDailyTime()));
    sessionUser::getInstance().setRowSelected(0);

}


void MainWindow::on_refreshTblBtn_clicked()
{
    refreshModel();
}


void MainWindow::on_deleteEntryBtn_clicked()
{
    if(ui->comboBox_rowNum->currentText().isEmpty())
    {
        QMessageBox::information(this,"No Row Selected","Please select a Row/Change Date before pressing Delete");
    }
    else
    {
        QMessageBox::StandardButton reply = QMessageBox:: critical(this,"Deleting Entry","Are you sure", QMessageBox::Yes |QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            DataBase::getInstance().removeEntry();
            refreshModel();
        }
    }

}


void MainWindow::on_managerBtn_clicked()
{
    if(sessionUser::getInstance().getIsManager())
    {
        newWindow = new managerMainWindow();
        newWindow->show();
    }
    else
        QMessageBox::information(this,"User Not Manager","User Not Manager for any Project");



}


void MainWindow::on_pushButton_clicked()
{
    monthlyActivity window;
    window.setModal(true);
    window.exec();
}

