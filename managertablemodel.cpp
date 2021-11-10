#include "managertablemodel.h"

managerTableModel::managerTableModel(const QList<user*> &userList,QObject *parent) : QAbstractTableModel(parent)
{
    for (auto us: userList)
    {
        if(us->getName() == sessionUser::getInstance().getTargetUserForManagerTable())
        {
            if(us->getEntries(sessionUser::getInstance().getManagerReportMonth()))
               {
                   for(auto ent: *us->getEntries(sessionUser::getInstance().getManagerReportMonth()))
                   {
                       if(sessionUser::getInstance().getIsManager() && (ent->getData(0).toString() == sessionUser::getInstance().getCodeManager()) )
                       {
                           managerTableDB* toAdd = new managerTableDB;
                           toAdd->date = ent->getData(4).toString();
                           toAdd->code = ent->getData(0).toString();
                           toAdd->subcode = ent->getData(1).toString();
                           toAdd->time = ent->getData(2).toInt();
                           toAdd->description = ent->getData(3).toString();
                           tableList.append(toAdd);
                       }

                   }
               }
        }

    }
}

int managerTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return tableList.length();
}

int managerTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 5;
}

QVariant managerTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        auto data = tableList.at(index.row());
        switch (index.column()){
        case 0:
            return data->code;
        case 1:
            return data->subcode;
        case 2:
            return data->time;
        case 3:
            return data->description;
        case 4:
            return data->date;
        }
    }

    return QVariant();
}

QVariant managerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Orientation::Horizontal){
        switch (section) {
        case 0:
            return QStringLiteral("Project Code");
        case 1:
            return QStringLiteral("Project SubCode");
        case 2:
            return QStringLiteral("Time");
        case 3:
            return QStringLiteral("Description");
        case 4:
            return QStringLiteral("Date");
        }
    }
    return QStringLiteral("%0").arg(section + 1);
}

void managerTableModel::initTable(QTableView &table)
{
    if (table.model()){
        table.model()->deleteLater();
    }

    table.setModel(this);
    table.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table.setEditTriggers(QAbstractItemView::NoEditTriggers);
    table.setFocusPolicy(Qt::NoFocus);
    table.setSelectionMode(QAbstractItemView::NoSelection);
}
