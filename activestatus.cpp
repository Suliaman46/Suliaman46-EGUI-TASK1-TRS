#include "activestatus.h"
#include "ui_activestatus.h"
#include "database.h"
#include "sessionuser.h"

activeStatus::activeStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activeStatus)
{
    ui->setupUi(this);
    ui->comboBox_code->addItems(DataBase::getInstance().getActivityCodeStringList());
}

activeStatus::~activeStatus()
{
    delete ui;
}

void activeStatus::on_comboBox_code_textActivated(const QString &arg1)
{
    ogStatus = DataBase::getInstance().getActiveStatus(arg1);
    QString boolText = ogStatus ? "true" : "false";
    ui->comboBox_status->addItem(boolText);
    if(boolText == "true")
         ui->comboBox_status->addItem("false");
    else
        ui->comboBox_status->addItem("true");

}


void activeStatus::on_pushButton_clicked()
{
    QString temp = ui->comboBox_status->currentText();
    bool tempBool = temp == "true" ? true: false;
    QStringList toCheck = sessionUser::getInstance().getCodeManager();
    if(toCheck.contains(ui->comboBox_code->currentText()))
    {
        DataBase::getInstance().setActiveStatus(ui->comboBox_code->currentText(),tempBool);
    }
    close();
}

