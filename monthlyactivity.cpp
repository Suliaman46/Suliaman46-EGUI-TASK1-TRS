#include "monthlyactivity.h"
#include "ui_monthlyactivity.h"
#include "monthlyactivitymodel.h"

monthlyActivity::monthlyActivity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monthlyActivity)
{
    ui->setupUi(this);
    monthlyActivityModel* myModel = new monthlyActivityModel(DataBase::getInstance().getUserList());
    myModel->initTable(*ui->monthlyTable);
    ui->monthlyTable->setModel(myModel);
}

monthlyActivity::~monthlyActivity()
{
    delete ui;
}
