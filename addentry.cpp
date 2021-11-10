#include "addentry.h"
#include "ui_addentry.h"
#include "database.h"
#include <QMessageBox>

addEntry::addEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEntry)
{
    ui->setupUi(this);
    setWindowTitle("ADD ENTRY");
    ui->comboBox_code->setPlaceholderText("Choose Code");
    ui->comboBox_code->setCurrentIndex(-1);
    ui->comboBox_code->addItems(DataBase::getInstance().getActivityCodeStringList());
}

addEntry::~addEntry()
{
    delete ui;
}


void addEntry::on_comboBox_code_textActivated(const QString &arg1)
{
    ui->comboBox_subCode->clear();
    ui->comboBox_subCode->addItems(DataBase::getInstance().subcodeList(arg1));

}


void addEntry::on_pushButton_enter_clicked()
{
    if(ui->comboBox_code->currentText().isEmpty() || ui->lineEdit_time->text().isEmpty())
        QMessageBox::information(this,"Invalid Inputs","Please input Code and Time");

    else
        DataBase::getInstance().addEntry(ui->comboBox_code->currentText(),
                                     ui->comboBox_subCode->currentText(),
                                     ui->lineEdit_time->text().toInt(),
                                     ui->lineEdit_description->text());
    close();
}

