#ifndef MONTHLYACTIVITYMODEL_H
#define MONTHLYACTIVITYMODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include "database.h"

struct TableDB {
    QString code;
    QString subcode;
    int time;
    QString description;
};
class monthlyActivityModel : public QAbstractTableModel
{
public:
    explicit monthlyActivityModel(const QList<user*> &userList,QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void initTable(QTableView& table);

private:
    QList<TableDB*> tableList;

};

#endif // MONTHLYACTIVITYMODEL_H
