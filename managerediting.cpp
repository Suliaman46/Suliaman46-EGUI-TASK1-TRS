#include "managerediting.h"
#include "ui_managerediting.h"
#include "database.h"

managerEditing::managerEditing(const QDate &date,const QString &userSelected,int RowSelected,QWidget *parent) :
    pDate(date), pUserSelected(userSelected), pRowSelected(RowSelected), QDialog(parent),
    ui(new Ui::managerEditing)
{
    ui->setupUi(this);
    setWindowTitle("EDIT APPROVED TIME");
    ui->comboBox_userName->setPlaceholderText(userSelected);
    ui->comboBox_userName->setCurrentIndex(-1);

    ui->comboBox_code->setPlaceholderText("Choose Code");
    ui->comboBox_code->setCurrentIndex(-1);
    ui->comboBox_code->addItems(sessionUser::getInstance().getCodeInSelectedMonth());
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

