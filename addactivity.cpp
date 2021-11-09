#include "addactivity.h"
#include "ui_addactivity.h"
#include "database.h"
#include "sessionuser.h"

addActivity::addActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addActivity)
{
    ui->setupUi(this);
}

addActivity::~addActivity()
{
    delete ui;
}

void addActivity::on_pushButton_clicked()
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

    close();
}


void addActivity::on_pushButton_2_clicked()
{
    for (int i = 0; i <9 ;++i ) {
            qDebug() <<ui->listWidget_subActivities->item(i)->text();
    }

}

