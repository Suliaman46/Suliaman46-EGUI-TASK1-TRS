#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>

namespace Ui {
class addEntry;
}

class addEntry : public QDialog
{
    Q_OBJECT

public:
    explicit addEntry(QWidget *parent = nullptr);
    ~addEntry();

private slots:



//    void on_comboBox_code_activated(const QString &arg1);

//    void on_comboBox_subCode_activated(const QString &arg1);

//    void on_comboBox_code_activated(int index);

    void on_comboBox_code_textActivated(const QString &arg1);

    void on_pushButton_enter_clicked();

private:
    Ui::addEntry *ui;
};

#endif // ADDENTRY_H
