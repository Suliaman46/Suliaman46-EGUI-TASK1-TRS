#include "database.h"


//DataBase::DataBase()
//{
//    DataBase::instance = this;
//}

//DataBase& DataBase::getInstance()
//{
//    return *DataBase::instance;
//}


void DataBase::addActivity(const QString &code, const QString &name, const QString &manager, bool active, int budget)
{
    activitiesList.create(code,name,manager,true,budget);
}

int DataBase::sizeActivities()
{
    return activitiesList.sizeActivities();
}
