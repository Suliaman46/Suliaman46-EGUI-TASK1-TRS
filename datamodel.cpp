#include "datamodel.h"
dataModel::dataModel(const QList<user> &userList,QObject *parent) : QAbstractTableModel(parent)
{
    for (auto us: userList)
    {
        if(us.getName() == sessionUser::getInstance().getUserName())
        {
            dailyActivitiesTableDB toAdd;
            toAdd.code = us.
        }
    }
}

int dataModel::rowCount(const QModelIndex &parent) const
{
    DataBase & DB = DataBase::getInstance();
    return DB.numEntries();
}

int dataModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant dataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        return DataBase::getInstance().getData(index.row(),index.column());
    }

    return QVariant();
}
