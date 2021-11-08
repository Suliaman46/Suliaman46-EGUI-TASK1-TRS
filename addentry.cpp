#include "addentry.h"
#include "ui_addentry.h"
#include "database.h"

addEntry::addEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEntry)
{
    ui->setupUi(this);
    ui->comboBox_code->addItems(DataBase::getInstance().getActivityCodeStringList());
}

addEntry::~addEntry()
{
    delete ui;
}


void addEntry::on_comboBox_code_textActivated(const QString &arg1)
{
    ui->comboBox_subCode->clear();
    qDebug() <<arg1;
    qDebug() <<"anything4";
    ui->comboBox_subCode->addItems(DataBase::getInstance().subcodeList(arg1));

}


void addEntry::on_pushButton_enter_clicked()
{
    DataBase::getInstance().addEntry(ui->comboBox_code->currentText(),ui->comboBox_subCode->currentText(),ui->lineEdit_time->text().toInt(),ui->lineEdit_description->text());
    close();
}

