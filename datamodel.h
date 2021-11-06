#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractTableModel>

class dataModel : public QAbstractTableModel
{
public:
    explicit dataModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;


};

#endif // DATAMODEL_H
