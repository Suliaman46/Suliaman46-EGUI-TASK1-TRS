#include "addactivity.h"
#include "ui_addactivity.h"

ADDACTIVITY::ADDACTIVITY(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ADDACTIVITY)
{
    ui->setupUi(this);
}

ADDACTIVITY::~ADDACTIVITY()
{
    delete ui;
}

void ADDACTIVITY::on_buttonBox_accepted()
{
    QString codeProject = ui->lineEdit_code->text();
    QString nameProject = ui->lineEdit_name->text();
    QString managerProject = ui->lineEdit_manager->text();
    int budgetProject = ui->lineEdit_budget->text().toInt();
//    DataBase::getInstance().addActivity(codeProject,nameProject,managerProject,true,budgetProject);
    DataBase & DB = DataBase::getInstance();
    DB.addActivity(codeProject,nameProject,managerProject,true,budgetProject);
}

