#include "addentry.h"
#include "ui_addentry.h"

addEntry::addEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEntry)
{
    ui->setupUi(this);
}

addEntry::~addEntry()
{
    delete ui;
}
