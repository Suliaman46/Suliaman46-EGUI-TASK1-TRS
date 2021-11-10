#include "editentry.h"
#include "ui_editentry.h"
#include "database.h"
#include <QMessageBox>

editEntry::editEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editEntry)
{
    codeEdited = subCodeEdited = timeEdited = descriptionEdited = false;
    setWindowTitle("EDIT ENTRY");
    ui->setupUi(this);
    int count = 1;
    bool activityObjectFound = false;
    for (auto us: DataBase::getInstance().getUserList())
    {
            for(auto ent: *us->getEntries(sessionUser::getInstance().getDate().toString("yyyy-MM")))
            {
                if(ent->getDate() == sessionUser::getInstance().getDate()){
                    if(count == sessionUser::getInstance().getRowSelected())
                    {
                        ui->comboBox_code->setPlaceholderText(ent->getData(0).toString());
                        ui->comboBox_code->setCurrentIndex(-1);
                        ui->comboBox_subCode->setPlaceholderText(ent->getData(1).toString());
                        ui->comboBox_subCode->setCurrentIndex(-1);
                        ui->lineEdit_time->setPlaceholderText(ent->getData(2).toString());
                        ui->lineEdit_description->setPlaceholderText(ent->getData(3).toString());
                        activityObjectFound = true;
                        break;
                    }
                    count++;
                }
            }
            if(activityObjectFound)
                break;
    }
    ui->comboBox_code->addItems(DataBase::getInstance().getActivityCodeStringList());
    ui->comboBox_subCode->addItems(DataBase::getInstance().subcodeList(ui->comboBox_code->placeholderText()));

}

editEntry::~editEntry()
{
    delete ui;
}

void editEntry::on_pushButton_clicked()
{
    if(ui->comboBox_code->currentText().isEmpty() || ui->lineEdit_time->text().isEmpty())
        QMessageBox::information(this,"Invalid Inputs","Please check your input Data");
    else
        DataBase::getInstance().editEntry(codeEdited ? ui->comboBox_code->currentText() : ui->comboBox_code->placeholderText(),
                                          subCodeEdited ? ui->comboBox_subCode->currentText() : ui->comboBox_subCode->placeholderText(),
                                          timeEdited ? ui->lineEdit_time->text().toInt() : ui->lineEdit_time->placeholderText().toInt(),
                                          descriptionEdited ? ui->lineEdit_description->text() : ui->lineEdit_description->placeholderText());
    close();
}


void editEntry::on_comboBox_code_textActivated(const QString &arg1)
{
    codeEdited = true;
    ui->comboBox_subCode->clear();
    ui->comboBox_subCode->addItems(DataBase::getInstance().subcodeList(arg1));
}

void editEntry::on_comboBox_subCode_textActivated(const QString &arg1)
{
    subCodeEdited = true;
}


void editEntry::on_lineEdit_time_textChanged(const QString &arg1)
{
    timeEdited = true;
}


void editEntry::on_lineEdit_description_textChanged(const QString &arg1)
{
    descriptionEdited = true;
}



