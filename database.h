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

    const QList<user*>& getUserList() const;
    const QList<activity*> getActivitiesList() const;

    QStringList subcodeList(const QString &code);
    QStringList  getActivityCodeStringList() const;
    QStringList getUserNameStringList() const;

    void editEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    void editApprovedTime(const QString& forUserName, const QString& Month,const QString& code ,int approvedTime);

    int getApprovedTime(const QString &monthYear, const QString & code);

    bool isMonthFrozen(const QString& monthYear, const QString& userName);

    bool getActiveStatus(const QString& code);

    void setActiveStatus(const QString& code, bool status);

    void removeEntry();
private:
//    inline static DataBase* theInstance;
    activities* activitiesList;
    QList<user*> userList;
    DataBase(){ activitiesList = new activities;} ;

};
#endif // DATABASE_H
