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

    MainWindow w;
    w.show();
    return a.exec();
}
