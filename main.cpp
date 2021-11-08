#include "mainwindow.h"
#include "sessionloginwindow.h"
#include "database.h"
#include <QTableView>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    sessionLoginWindow sL;
    sL.show();
//    return a.exec();

//    DataBase::getInstance().read();
//    sessionUser::getInstance().setDate(QDate::fromString("2021-11-07","yyyy-MM-dd"));
//    QTableView tableView;
//    dataModel myModel;
//    tableView.setModel(&myModel);
//    tableView.show();

    MainWindow w;
    w.show();
    return a.exec();
}
