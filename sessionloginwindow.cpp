#include "sessionloginwindow.h"
#include "ui_sessionloginwindow.h"
#include "mainwindow.h"


sessionLoginWindow::sessionLoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sessionLoginWindow)
{
    ui->setupUi(this);
}

sessionLoginWindow::~sessionLoginWindow()
{
    delete ui;
}

void sessionLoginWindow::on_pushButton_clicked()
{
    sessionUser::getInstance().setUserName(ui->lineEdit_userName->text());
    DataBase::getInstance().read();
    for(auto act: DataBase::getInstance().getActivitiesList())
    {
        if(act->manager() == sessionUser::getInstance().getUserName())
        {
            sessionUser::getInstance().setIsManager(true);
            sessionUser::getInstance().setCodeManager(act->code());
            break;
        }
        else
            sessionUser::getInstance().setIsManager(false);
    }
    this->hide();
}

