#ifndef MANAGEREDITING_H
#define MANAGEREDITING_H

#include <QDialog>
#include <QDate>

namespace Ui {
class managerEditing;
}

class managerEditing : public QDialog
{
    Q_OBJECT

public:
    explicit managerEditing(const QString& userSelected,QWidget *parent = nullptr);
    ~managerEditing();

private slots:
    void on_pushButton_clicked();

private:
    Ui::managerEditing *ui;

};

#endif // MANAGEREDITING_H
