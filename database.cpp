#include "database.h"

void DataBase::addActivity(const QString &code, const QString &name, const QString &manager, bool active, int budget)
{
    activitiesList->create(code,name,manager,true,budget);
}

void DataBase::addEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    foreach(user* us, userList)
    {
        if(us->getName() == sessionUser::getInstance().getUserName())
        {
            us->addEntry(code,subcode,time,description);
        }
    }
}

int DataBase::sizeActivities()
{
    return activitiesList->sizeActivities();
}


const QList<user*>& DataBase::getUserList() const
{
    return userList;
}

QStringList DataBase::getActivityCodeStringList() const
{
    QStringList toReturn ;
    for(auto act: activitiesList->getActivitiesList())
    {
        toReturn.append(act->code());
    }

    return toReturn;
}


void DataBase::read()
{
    /////////Reading Activities/////////////////////

    QString dirAct = "/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/DATABASE/activity.json";
    QFile file(dirAct);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    activitiesList->read(object);


    //////////Reading User Entry ///////////////////////


    QString dir = "/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/DATABASE/USERS";
    QDir userDirectory(dir);
    QStringList list = userDirectory.entryList();


//    QString filename = pDirectory.absolutePath()+"/";
//    QStringList list = pDirectory.entryList(filters);
    for (int i = 0; i< list.size(); ++i)
    {
        qDebug()<< list.at(i);
        if(sessionUser::getInstance().getUserName() == list.at(i))
        {
            user* userToAdd = new user(list.at(i), dir);
            userToAdd->read();
            userList.append(userToAdd);
        }

//        filename = filename + list.at(i);
//        QFile file(filename);
//        file.open(QIODevice::ReadOnly | QIODevice::Text);
//        QByteArray jsonData = file.readAll();
//        file.close();

//        QJsonDocument document = QJsonDocument::fromJson(jsonData);
//        QJsonObject object = document.object();

//        month temp(filename.right(7));
//        temp.read(object);
//        monthlyReports.append(temp);

    }






}

void DataBase::write()
{
    //////////Writing Activties ///////////////////////

    QFile saveFile("/home/suliaman/EGUI2021Z/egui2021z-abass-suliaman/DATABASE/activity.json");
    if (!saveFile.open(QIODevice::WriteOnly)) {
           qWarning("Couldn't open save file.");
       }
    QJsonObject activitiesObject;
    activitiesList->write(activitiesObject);

    QJsonDocument saveActivities(activitiesObject);
    saveFile.write(saveActivities.toJson());
    saveFile.close();

    ///  QFile saveFile(QString(basePath + "/users.json"));

    //////////Writing User Entry ///////////////////////
    for(auto us: userList)
    {
        us->write();
    }

}

QStringList DataBase::subcodeList(const QString &code)
{
    QStringList toReturn ;
    for(auto act: activitiesList->getActivitiesList())
    {
        if(act->code() == code)
        {
            return act->getSubactivities();
        }
    }
    return toReturn;

}
