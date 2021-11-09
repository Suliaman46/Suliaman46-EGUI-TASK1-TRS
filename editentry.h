#ifndef EDITENTRY_H
#define EDITENTRY_H

#include <QDialog>

namespace Ui {
class editEntry;
}

class editEntry : public QDialog
{
    Q_OBJECT

public:
    explicit editEntry(QWidget *parent = nullptr);
    ~editEntry();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_code_textActivated(const QString &arg1);

    void on_lineEdit_time_textChanged(const QString &arg1);

    void on_lineEdit_description_textChanged(const QString &arg1);

    void on_comboBox_subCode_textActivated(const QString &arg1);

private:
    Ui::editEntry *ui;
    bool codeEdited;
    bool subCodeEdited;
    bool timeEdited;
    bool descriptionEdited;
};

#endif // EDITENTRY_H
