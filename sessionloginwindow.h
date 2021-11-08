#include<sessionuser.h>
#ifndef SESSIONLOGINWINDOW_H
#define SESSIONLOGINWINDOW_H

#include <QDialog>

namespace Ui {
class sessionLoginWindow;
}

class sessionLoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit sessionLoginWindow(QWidget *parent = nullptr);
    ~sessionLoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sessionLoginWindow *ui;
};

#endif // SESSIONLOGINWINDOW_H
