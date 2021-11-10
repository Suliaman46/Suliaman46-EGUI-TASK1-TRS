#include "managerediting.h"
#include "ui_managerediting.h"
#include "database.h"
#include <QMessageBox>

managerEditing::managerEditing(const QString& userSelected,QWidget *parent) :
     QDialog(parent),
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
    if(ui->lineEdit_time->text().isEmpty())
        QMessageBox::information(this,"Invalid Inputs","Please input Time");
    else
    {

        DataBase::getInstance().editApprovedTime(ui->comboBox_userName->currentText().isEmpty() ? ui->comboBox_userName->placeholderText(): ui->comboBox_userName->currentText(),
                                                 sessionUser::getInstance().getManagerReportMonth(),
                                                 ui->comboBox_code->currentText().isEmpty() ? ui->comboBox_code->placeholderText() : ui->comboBox_code->currentText(),
                                                 ui->lineEdit_time->text().toInt());
    }

    close();
}

