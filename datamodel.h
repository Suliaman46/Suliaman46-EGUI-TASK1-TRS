#ifndef DATAMODEL_H
#define DATAMODEL_H
#include "database.h"
#include <QAbstractTableModel>
#include<QTableView>
#include <QHeaderView>


struct dailyActivitiesTableDB {
    QString code;
    QString subcode;
    int time;
    QString description;
};

class dataModel : public QAbstractTableModel
{
public:
    explicit dataModel(const QList<user*> &userList,QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void initTable(QTableView& table);
private:
    QList<dailyActivitiesTableDB*> tableList;
};

#endif // DATAMODEL_H
