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

private:
    Ui::addEntry *ui;
};

#endif // ADDENTRY_H
