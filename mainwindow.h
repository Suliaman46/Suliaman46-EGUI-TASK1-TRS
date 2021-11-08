
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "datamodel.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


   void on_tableView_activated(const QModelIndex &index);

    void on_dateEdit_userDateChanged(const QDate &date);


    void on_addEntryBtn_clicked();

    void on_saveJsonBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
