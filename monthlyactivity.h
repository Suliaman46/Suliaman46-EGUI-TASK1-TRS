#ifndef MONTHLYACTIVITY_H
#define MONTHLYACTIVITY_H

#include <QDialog>

namespace Ui {
class monthlyActivity;
}

class monthlyActivity : public QDialog
{
    Q_OBJECT

public:
    explicit monthlyActivity(QWidget *parent = nullptr);
    ~monthlyActivity();

private:
    Ui::monthlyActivity *ui;
};

#endif // MONTHLYACTIVITY_H
