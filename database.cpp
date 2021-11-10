#include "database.h"
#include <QCoreApplication>

void DataBase::addActivity(const QString &code, const QString &name, const QString &manager, bool active, int budget,const QStringList& newSubactivities )
{
    activitiesList->create(code,name,manager,active,budget, newSubactivities);
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

const QList<activity *> DataBase::getActivitiesList() const
{
    return this->activitiesList->getActivitiesList();
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

QStringList DataBase::getUserNameStringList() const
{
    QStringList toReturn;
    for(auto us: userList)
    {
        toReturn.append(us->getName());
    }
    return toReturn;
}

void DataBase::editEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    for(auto us: userList)
    {
        if(us->getName() == sessionUser::getInstance().getUserName())
        {
            us->editEntry(code,subcode,time,description);
        }
    }
}

void DataBase::editApprovedTime(const QString &forUserName, const QString &Month, const QString& code,int approvedTime)
{
    for (auto us :userList ) {
        if(us->getName() == forUserName)
        {
            if(us->getEntries(Month))
            {
                if(us->getAccepted(Month))
                {
                    for (auto accepted : *us->getAccepted(Month) )
                    {
                        if(accepted->getPCode() == code)
                        {
                            accepted->setPTime(approvedTime);
                        }
                    }
                }

                accepted* toAdd = new accepted();
                toAdd->setPCode(code);
                toAdd->setPTime(approvedTime);
            }
        }
    }
}

void DataBase::removeEntry()
{
    for (auto us: userList)
    {
        if(us->getName() == sessionUser::getInstance().getUserName())
            us->removeEntry();
    }
}


void DataBase::read()
{
    QDir directory(QCoreApplication::applicationDirPath());
    directory.cdUp();
    directory.cd("egui2021z-abass-suliaman/DATABASE");

    /////////Reading Activities/////////////////////

    QString dirAct = directory.absoluteFilePath("activity.json");
    QFile file(dirAct);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonObject object = document.object();
    activitiesList->read(object);


    //////////Reading User Entry ///////////////////////



    directory.cd("USERS");

    QString dir = directory.absolutePath();
    QDir userDirectory(directory);
    QStringList list = userDirectory.entryList(QDir::NoDot | QDir::NoDotDot | QDir::Dirs);

    bool userFound = false;
    for (int i = 0; i< list.size(); ++i)
    {
            user* userToAdd = new user(list.at(i), dir);
            userToAdd->read();
            userList.append(userToAdd);
            userFound = true;
    }

    if(!getUserNameStringList().contains(sessionUser::getInstance().getUserName()))
    {
        QString userName = sessionUser::getInstance().getUserName();
        if(!userDirectory.exists(userName))
            userDirectory.mkpath(userName);
        user* userToAdd = new user(userName,dir);
        userList.append(userToAdd);
    }

}

void DataBase::write()
{
    //////////Writing Activties ///////////////////////
    QDir directory(QCoreApplication::applicationDirPath());
    directory.cdUp();
    directory.cd("egui2021z-abass-suliaman/DATABASE");

    QFile saveFile(directory.absolutePath()+"/"+"activity.json");
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


