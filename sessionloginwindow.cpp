#include "sessionloginwindow.h"
#include "ui_sessionloginwindow.h"
#include "mainwindow.h"


sessionLoginWindow::sessionLoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sessionLoginWindow)
{
    ui->setupUi(this);
    setWindowTitle("LOGIN");

}

sessionLoginWindow::~sessionLoginWindow()
{
    delete ui;
}

void sessionLoginWindow::on_pushButton_clicked()
{
    bool Flag = false;
    QStringList toPass;

    sessionUser::getInstance().setUserName(ui->lineEdit_userName->text());
    DataBase::getInstance().read();
    for(auto act: DataBase::getInstance().getActivitiesList())
    {
        if(act->manager() == sessionUser::getInstance().getUserName())
        {
            sessionUser::getInstance().setIsManager(true);
            toPass.append(act->code());
            Flag = true;
        }

    }
    if(!Flag)
        sessionUser::getInstance().setIsManager(false);
    else
        sessionUser::getInstance().setCodeManager(toPass);

    this->hide();
}

