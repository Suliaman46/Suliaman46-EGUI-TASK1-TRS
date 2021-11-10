#include "managerediting.h"
#include "ui_managerediting.h"
#include "database.h"

managerEditing::managerEditing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerEditing)
{
    ui->setupUi(this);
    ui->comboBox_userName->setPlaceholderText("Select User");
    ui->comboBox_userName->setCurrentIndex(-1);
    ui->comboBox_userName->addItems(DataBase::getInstance().getUserNameStringList());
    ui->comboBox_code->setPlaceholderText("Choose Code");
    ui->comboBox_code->setCurrentIndex(-1);
    ui->comboBox_code->addItems(DataBase::getInstance().getActivityCodeStringList());
}

managerEditing::~managerEditing()
{
    delete ui;
}

void managerEditing::on_pushButton_clicked()
{
    DataBase::getInstance().editApprovedTime(ui->comboBox_userName->currentText(),
                                             sessionUser::getInstance().getManagerReportMonth(),
                                             ui->comboBox_code->currentText(),
                                             ui->lineEdit_time->text().toInt());
}

