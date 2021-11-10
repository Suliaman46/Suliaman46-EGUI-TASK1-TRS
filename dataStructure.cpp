#include"dataStructure.h"
#include<iostream>
activity::activity()
{}

activity::activity(const QString &code,const QString &name,const QString &manager, bool active, int budget): pCode(code), pName(name), pManager(manager),pActive(active),pBudget(budget)
{
}

QString activity::code() const
{
    return pCode;
}

void activity::setCode(const QString &code)
{
    pCode = code;
}


QString activity::manager() const
{
    return pManager;
}

void activity::setManager(const QString &manager)
{
    pManager = manager;
}

QString activity::name() const
{
    return pName;
}

void activity::setName(const QString &name)
{
    pName = name;
}

bool activity::active() const
{
    return pActive;
}

void activity::setActive(bool active)
{
    pActive = active;
}

int activity::budget() const
{
    return pBudget;
}

void activity::setBudget(int budget)
{
    pBudget = budget;
}

void activity::read(const QJsonObject &json)
{
    pName = json["name "].toString();
    pManager = json["manager "].toString();
    pCode = json["code "].toString();
    pBudget= json["budget "].toInt();
    pActive = json["active "].toBool();

    QJsonArray subactivitiesArray =  json["subactivities "].toArray();
    for(int index = 0; index < subactivitiesArray.size(); ++index)
    {
                QJsonObject subactivityObject = subactivitiesArray[index].toObject();
                this->subactivities.append(subactivityObject.value("code ").toString());

    }


}

void activity::write(QJsonObject &json) const
{
    json["name "] = pName ;
    json["manager "] = pManager;
    json["code "] = pCode ;
    json["budget "] = pBudget ;
    json["active "] = pActive ;

    QJsonArray subactivitiesArray;
    foreach(const QString subactivity, subactivities)
    {
        QJsonObject subactivityObject;
        subactivityObject["code "] = subactivity;
        subactivitiesArray.append(subactivityObject);
    }

    json["subactivities "] = subactivitiesArray;

}

QStringList activity::getSubactivities() const
{
    QStringList toReturn;
    foreach(const QString str,subactivities)
    {
        toReturn.append(str);
    }
    return toReturn;
}

void activity::setSubactivities(const QStringList &newSubactivities)
{
    subactivities = newSubactivities;
}



activities::activities()
{

}

void activities::read(const QJsonObject &json)
{
    QJsonArray attributeArray = json["activities "].toArray();
    for(int index = 0; index < attributeArray.size(); ++index)
    {
        QJsonObject attributeObject = attributeArray[index].toObject();
        activity* attributes = new activity();
        attributes->read(attributeObject);
        pActivitiesList.append(attributes);

    }

}

void activities::write(QJsonObject &json) const
{
    QJsonArray attributeArray;
    foreach(const activity* act,pActivitiesList)
    {
        QJsonObject activityObject;
        act->write(activityObject);
        attributeArray.append(activityObject);
    }
    json["activities "] = attributeArray;

}

void activities::create(const QString &code,const QString &name,const QString &manager, bool active, int budget,const QStringList& newSubactivities )
{
    activity* new_act = new activity(code,name,manager,active,budget);
    new_act->setSubactivities(newSubactivities);
    pActivitiesList.append(new_act);
}

int activities::sizeActivities()
{
    return pActivitiesList.length();
}

QStringList activities::subcodeList(const QString code)
{
    foreach(const activity* act,  pActivitiesList)
    {
        if(act->code() == code)
        {
            return act->getSubactivities();
        }
    }

    return QStringList(); //else returning empty string list
}

const QList<activity *> &activities::getActivitiesList() const
{
    return pActivitiesList;
}


entry::entry()
{}

entry::entry(const QString &code,const QString &subcode,const QString &description,int time, const QDate &date): pCode(code),pSubcode(subcode),pDescription(description),pTime(time),pDate(date)
{}

void entry::read(const QJsonObject &json)
{
    pSubcode = json["subcode "].toString();
    pDescription = json["description "].toString();
    pCode = json["code "].toString();
    pTime= json["time "].toInt();
    QString debugString = json["date "].toString().left(10);
    pDate = QDate::fromString(debugString,"yyyy-MM-dd");
}

void entry::write(QJsonObject &json) const
{
    json["date "] = pDate.toString("yyyy-MM-dd");
    json["code "] = pCode;
    json["subcode "]= pSubcode;
    json["time "]= pTime;
    json["description "]= pDescription;
}

QDate entry::getDate() const
{
    return pDate;
}

void entry::setPCode(const QString &newPCode)
{
    pCode = newPCode;
}

void entry::setPSubcode(const QString &newPSubcode)
{
    pSubcode = newPSubcode;
}

void entry::setPDescription(const QString &newPDescription)
{
    pDescription = newPDescription;
}

void entry::setPTime(int newPTime)
{
    pTime = newPTime;
}

QVariant entry::getData(int index) const
{
    switch (index) {
    case 0:
        return pCode;
        break;
    case 1:
        return pSubcode;
    case 2:
        return pTime;
    case 3:
        return pDescription;
    case 4:
        return pDate.toString("yyyy-MM-dd");

    }
}

void accepted::read(const QJsonObject &json)
{
    pCode = json["code "].toString();
    pTime = json["time "].toInt();
}

void accepted::write(QJsonObject &json) const
{
    json["code "] = pCode;
    json["time "] = pTime;
}

const QString &accepted::getPCode() const
{
    return pCode;
}

void accepted::setPCode(const QString &newPCode)
{
    pCode = newPCode;
}

int accepted::getPTime() const
{
    return pTime;
}

void accepted::setPTime(int newPTime)
{
    pTime = newPTime;
}

month::month(QString monthYear)
{
    pMonthYear = QDate::fromString(monthYear,"yyyy-mm");
    pMY = monthYear;
}
void month::read(const QJsonObject &json)
{
    pFrozen = json["frozen "].toBool();
    QJsonArray entryArray = json["entries "].toArray();
    for(int index = 0; index < entryArray.size(); ++index)
    {
        QJsonObject attributeObject = entryArray[index].toObject();
        entry * attributes = new entry();
        attributes->read(attributeObject);
        pEntries.append(attributes);

    }

    QJsonArray acceptedArray = json["accepted "].toArray();
    for(int index = 0; index < acceptedArray.size(); ++index)
    {
        QJsonObject acceptedObject = acceptedArray[index].toObject();
        accepted *project = new accepted();
        project->read(acceptedObject);
        pAcceptedTimes.append(project);
    }

}

void month::write(QJsonObject &json) const
{

    QJsonArray acceptedArray;
    foreach(const accepted* act, pAcceptedTimes)
    {
        QJsonObject acceptedObject;
        act->write(acceptedObject);
        acceptedArray.append(acceptedObject);
    }
    json["accepted "] = acceptedArray;

    QJsonArray entryArray;
    foreach(const entry* ent,pEntries)
    {
        QJsonObject activityObject;
        ent->write(activityObject);
        entryArray.append(activityObject);
    }
    json["entries "] = entryArray;

    json["frozen "] = pFrozen;


}


void month::addEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    entry* toAdd = new entry(code,subcode,description,time,sessionUser::getInstance().getDate());
    pEntries.append(toAdd);
}

void month::editEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    int count = 1;
    for(auto ent: pEntries)
    {
        if(ent->getDate() == sessionUser::getInstance().getDate())
        {
            if(count == sessionUser::getInstance().getRowSelected())
            {
                ent->setPCode(code);
                ent->setPSubcode(subcode);
                ent->setPTime(time);
                ent->setPDescription(description);
            }
            count++;
        }

    }
}

void month::removeEntry()
{
    int count = 1;
    for(auto ent: pEntries)
    {
        if(ent->getDate() == sessionUser::getInstance().getDate())
        {
            if(count == sessionUser::getInstance().getRowSelected())
            {
               pEntries.removeOne(ent);
            }
            count++;
        }

    }
}

bool month::getPFrozen() const
{
    return pFrozen;
}

void month::setPFrozen(bool newPFrozen)
{
    pFrozen = newPFrozen;
}


int month::getNumEntries() const
{
    return pEntries.size();
}

const QList<entry*> *month::getEntries() const
{
    return &pEntries;
}

const QList<accepted *> *month::getAccepted() const
{
    return &pAcceptedTimes;
}
user::user()
{

}

user::user(QString name, QString dir): pName(name)
{
    pDirectory = dir + "/"+ name;
}
void user::read()
{
    QStringList filters;
    filters << "*.json";
    QString filename = pDirectory.absolutePath()+"/";
    QStringList list = pDirectory.entryList(filters);
    for (int i = 0; i< list.size(); ++i)
    {

        qDebug()<< list.at(i);
        filename = filename + list.at(i);
        QFile file(filename);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray jsonData = file.readAll();
        file.close();

        QJsonDocument document = QJsonDocument::fromJson(jsonData);
        QJsonObject object = document.object();

        month* toAdd = new month(filename.right(12).left(7));
        toAdd->read(object);
        monthlyReports.append(toAdd);

    }
}

void user::write()
{
//    if(pDirectory.exists(pName))
//    {
//        qDebug() << "path found";
//        return;
//    }

//    qDebug()<<"Not found";
////    QFile saveReports("")
///
    foreach(const month *report, monthlyReports)
    {
        QFile saveFile(pDirectory.absolutePath()+"/"+pName+"-"+report->pMY+".json");
        if (!saveFile.open(QIODevice::WriteOnly)) {
               qWarning("Couldn't open save file.");
           }
        QJsonObject reportObject;
        report->write(reportObject);

        QJsonDocument saveReport(reportObject);
        saveFile.write(saveReport.toJson());
        saveFile.close();
    }

}

QString user::getName() const
{
    return pName;
}


void user::addEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    bool monthFound =false;
    for(auto report: monthlyReports)
    {
        if(report->pMY == sessionUser::getInstance().getDate().toString("yyyy-MM"))
        {
            monthFound = true;
            report->addEntry(code,subcode,time,description);
        }
    }

    if(!monthFound)
    {
        month* toAdd = new month(sessionUser::getInstance().getDate().toString("yyyy-MM"));
        toAdd->setPFrozen(false);
        monthlyReports.append(toAdd);
        addEntry(code,subcode,time,description);
    }


}

const QList<entry*> *user::getEntries(QString targetMonthYear) const
{
    for(auto report:monthlyReports)
    {
        if(targetMonthYear == report->pMY)
        {
            return report->getEntries();
        }
    }

    return nullptr;

}

const QList<accepted *> *user::getAccepted(QString targetMonthYear) const
{
    for(auto report:monthlyReports)
    {
        if(targetMonthYear == report->pMY)
        {
            return report->getAccepted();
        }
    }

    return nullptr;
}

void user::editEntry(const QString &code, const QString &subcode, int time, const QString &description)
{
    for(auto report: monthlyReports)
    {
        if(report->pMY == sessionUser::getInstance().getDate().toString("yyyy-MM"))
        {
            report->editEntry(code,subcode,time,description);
        }
    }
}

void user::removeEntry()
{
    for(auto report: monthlyReports)
    {
        if(report->pMY == sessionUser::getInstance().getDate().toString("yyyy-MM"))
        {
            report->removeEntry();
        }
    }
}

bool user::isMonthFrozen(const QString &monthYear)
{
    for(auto report: monthlyReports)
    {
        if(report->pMY == monthYear)
        {
            return report->getPFrozen();
        }
    }
}

















