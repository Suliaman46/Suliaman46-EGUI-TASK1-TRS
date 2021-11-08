#include<database.h>
#ifndef ADDACTIVITY_H
#define ADDACTIVITY_H

#include <QDialog>

namespace Ui {
class ADDACTIVITY;
}

class ADDACTIVITY : public QDialog
{
    Q_OBJECT

public:
    explicit ADDACTIVITY(QWidget *parent = nullptr);
    ~ADDACTIVITY();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::ADDACTIVITY *ui;
};

#endif // ADDACTIVITY_H
