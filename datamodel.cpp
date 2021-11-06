#include "datamodel.h"
#include "database.h"
dataModel::dataModel(QObject *parent) : QAbstractTableModel(parent)
{

}

int dataModel::rowCount(const QModelIndex &parent) const
{
    DataBase & DB = DataBase::getInstance();
    return DB.sizeActivities();
}

int dataModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant dataModel::data(const QModelIndex &index, int role) const
{
//    if (!index.isValid())
//        return QVariant();

}
