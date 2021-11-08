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
//    QString subcodeProject = ui->lineEdit_subcode->text();
    QString descriptionProject = ui->lineEdit_description->text();
    int time = ui->lineEdit_time->text().toInt();
//    DataBase::getInstance().addEntry(codeProject,subcodeProject,time,descriptionProject);
}


void ADDACTIVITY::on_comboBox_activated(const QString &arg1)
{
//    QStringList subcodeList;
    ui->comboBox->insertItems(0,DataBase::getInstance().subcodeList(ui->lineEdit_code->text()));
}

