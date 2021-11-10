#ifndef ACTIVESTATUS_H
#define ACTIVESTATUS_H

#include <QDialog>

namespace Ui {
class activeStatus;
}

class activeStatus : public QDialog
{
    Q_OBJECT

public:
    explicit activeStatus(QWidget *parent = nullptr);
    ~activeStatus();

private slots:
    void on_comboBox_code_textActivated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::activeStatus *ui;
    bool ogStatus;
};

#endif // ACTIVESTATUS_H
