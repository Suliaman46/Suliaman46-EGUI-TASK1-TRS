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
    QString userName = ui->lineEdit_userName->text();
    sessionUser & SU = sessionUser::getInstance();
    SU.setUserName(userName);
    this->hide();
}

