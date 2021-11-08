#include "dataStructure.h"
#include "sessionuser.h"
#ifndef DATAHANDLING\DATABASE_H
#define DATAHANDLING\DATABASE_H


class DataBase
{
public:
    static DataBase & getInstance(){
        static DataBase theInstance;
        return theInstance;
    }

    void addActivity(const QString &code,const QString &name,const QString &manager, bool active, int budget);
    void addEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    QVariant getData(int row, int column);
    int sizeActivities();
    void read();
    int numEntries() const;

    QStringList subcodeList(const QString &code);
    QList<user>& getUserList();
private:
    activities activitiesList;
    QList<user> userList;
    DataBase(){} ;

};
#endif // DATAHANDLING\DATABASE_H
