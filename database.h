#include "dataStructure.h"
#ifndef DATABASE_H
#define DATABASE_H




//class DataBase
//{
//public:
//    static DataBase & getInstance();
//    DataBase() ;
//    activities activitiesList;
//    QList<user> userList;
//    void addActivity(const QString &code,const QString &name,const QString &manager, bool active, int budget);

//private:
//    inline static DataBase *instance;

//};


class DataBase
{
public:
    static DataBase & getInstance(){
        static DataBase theInstance;
        return theInstance;
    }

    void addActivity(const QString &code,const QString &name,const QString &manager, bool active, int budget);
    int sizeActivities();

private:
    activities activitiesList;
    QList<user> userList;
    DataBase(){} ;

};
#endif // DATABASE_H
