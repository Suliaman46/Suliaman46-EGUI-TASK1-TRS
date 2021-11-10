#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "database.h"
#include "sessionuser.h"
#include "managerediting.h"
#include "managertablemodel.h"

managerMainWindow::managerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::managerMainWindow)
{
    ui->setupUi(this);
    ui->comboBox_userName->setPlaceholderText("Select User");
    ui->comboBox_userName->setCurrentIndex(-1);
    ui->comboBox_userName->addItems(DataBase::getInstance().getUserNameStringList());
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

}

void managerMainWindow::on_pushButton_clicked()
{
    managerEditing managerEditingWindow;
    managerEditingWindow.setModal(true);
    managerEditingWindow.exec();
}


void managerMainWindow::on_comboBox_userName_textActivated(const QString &arg1)
{
    sessionUser::getInstance().setTargetUserForManagerTable(arg1);
}


void managerMainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    sessionUser::getInstance().setManagerReportMonth(date.toString("yyyy-MM"));
    refreshModel();

}

