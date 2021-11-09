#include "dataStructure.h"
#include "sessionuser.h"
#include "datamodel.h"
#ifndef DATABASE_H
#define DATABASE_H


class DataBase
{
public:
    static DataBase & getInstance(){
        static DataBase theInstance;
//        return *DataBase::theInstance;
        return theInstance;
    }

    void addActivity(const QString &code,const QString &name,const QString &manager, bool active, int budget,const QStringList& newSubactivities );
    void addEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    QVariant getData(int row, int column);
    int sizeActivities();
    void read();
    void write();
//    int numEntries() const;

    QStringList subcodeList(const QString &code);
    const QList<user*>& getUserList() const;
    QStringList  getActivityCodeStringList() const;

    void editEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    void removeEntry();
private:
//    inline static DataBase* theInstance;
    activities* activitiesList;
    QList<user*> userList;
    DataBase(){ activitiesList = new activities;} ;

};
#endif // DATABASE_H
