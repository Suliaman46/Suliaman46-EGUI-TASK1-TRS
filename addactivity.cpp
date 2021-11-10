#include "addactivity.h"
#include "ui_addactivity.h"
#include "database.h"
#include "sessionuser.h"
#include <QMessageBox>

addActivity::addActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addActivity)
{
    ui->setupUi(this);
    setWindowTitle("ADD ACTIVITY");
}

addActivity::~addActivity()
{
    delete ui;
}

void addActivity::on_pushButton_clicked()
{
    if(ui->lineEdit_code->text().isEmpty() || ui->lineEdit_budget->text().isEmpty())
        QMessageBox::information(this,"Invalid Inputs","Please enter code and budget Data");
    else
    {
        QStringList subActivitiesList;
        for (int i = 0; i <9 ;++i ) {
            if(!ui->listWidget_subActivities->item(i)->text().isEmpty())
                subActivitiesList.append( ui->listWidget_subActivities->item(i)->text());
        }


        DataBase::getInstance().addActivity(
                    ui->lineEdit_code->text(),
                    ui->lineEdit_name->text(),
                    sessionUser::getInstance().getUserName(),
                    true,
                    ui->lineEdit_budget->text().toInt(),subActivitiesList);

        sessionUser::getInstance().setIsManager(true);
        sessionUser::getInstance().appendCodeManager(ui->lineEdit_code->text());
        close();
    }

}


void addActivity::on_pushButton_2_clicked()
{
    for (int i = 0; i <9 ;++i ) {
            qDebug() <<ui->listWidget_subActivities->item(i)->text();
    }

}

