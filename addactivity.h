#ifndef ADDACTIVITY_H
#define ADDACTIVITY_H

#include <QDialog>

namespace Ui {
class addActivity;
}

class addActivity : public QDialog
{
    Q_OBJECT

public:
    explicit addActivity(QWidget *parent = nullptr);
    ~addActivity();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addActivity *ui;
};

#endif // ADDACTIVITY_H
