#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class managerMainWindow;
}

class managerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit managerMainWindow(QWidget *parent = nullptr);
    ~managerMainWindow();

private slots:

    void refreshModel();
    void on_pushButton_clicked();

    void on_comboBox_userName_textActivated(const QString &arg1);

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::managerMainWindow *ui;
};

#endif // MANAGERMAINWINDOW_H
