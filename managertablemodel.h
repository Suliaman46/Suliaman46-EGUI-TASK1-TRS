#ifndef MANAGERTABLEMODEL_H
#define MANAGERTABLEMODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include "database.h"

struct managerTableDB {
    QString date;
    QString code;
    QString subcode;
    int time;
    QString description;
};

class managerTableModel : public QAbstractTableModel
{
public:
    explicit managerTableModel(const QList<user*> &userList,QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void initTable(QTableView& table);
private:
    QList<managerTableDB*> tableList;

};

#endif // MANAGERTABLEMODEL_H
