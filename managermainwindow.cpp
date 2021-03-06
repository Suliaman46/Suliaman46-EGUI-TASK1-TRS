#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "database.h"
#include "sessionuser.h"
#include "managerediting.h"
#include "managertablemodel.h"
#include "activestatus.h"

managerMainWindow::managerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managerMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Monthly Entries Table");
    ui->comboBox_userName->setPlaceholderText("Select User");
    ui->comboBox_userName->setCurrentIndex(-1);
    ui->comboBox_userName->addItems(DataBase::getInstance().getUserNameStringList());
    ui->comboBox_approvedTime->setPlaceholderText("Select Code");
    ui->comboBox_approvedTime->setCurrentIndex(-1);
}

managerMainWindow::~managerMainWindow()
{
    delete ui;
}

void managerMainWindow::refreshModel()
{
    managerTableModel* myModel = new managerTableModel(DataBase::getInstance().getUserList());
    myModel->initTable(*ui->managerTblView);
    ui->managerTblView->setModel(myModel);
    ui->comboBox_approvedTime->clear();
    ui->label_approvedTime->clear();
    ui->comboBox_approvedTime->addItems(sessionUser::getInstance().getCodeInSelectedMonth());
    ui->label_frozen->setText((DataBase::getInstance().isMonthFrozen(ui->dateEdit->date().toString("yyyy-MM"),ui->comboBox_userName->currentText()))? "true":"false" );

    if(ui->comboBox_approvedTime->currentIndex() == -1)
    {
        ui->pushButton->setEnabled(false);
    }
}

void managerMainWindow::on_pushButton_clicked()
{
    managerEditing managerEditingWindow(ui->comboBox_userName->currentText());
    managerEditingWindow.setModal(true);
    managerEditingWindow.exec();
    refreshModel();
}


void managerMainWindow::on_comboBox_userName_textActivated(const QString &arg1)
{
    sessionUser::getInstance().setTargetUserForManagerTable(arg1);
    refreshModel();
}


void managerMainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    sessionUser::getInstance().setManagerReportMonth(date.toString("yyyy-MM"));
    refreshModel();

}


void managerMainWindow::on_comboBox_approvedTime_textActivated(const QString &arg1)
{
    int time = DataBase::getInstance().getApprovedTime(ui->dateEdit->date().toString("yyyy-MM"),arg1);
    ui->label_approvedTime->setText(QString::number(time));
    ui->pushButton->setEnabled(true);

}


void managerMainWindow::on_pushButton_activeStatus_clicked()
{
    activeStatus activeStatusWindow;
    activeStatusWindow.setModal(true);
    activeStatusWindow.exec();
}

