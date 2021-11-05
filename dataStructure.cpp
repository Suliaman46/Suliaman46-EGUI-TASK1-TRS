#include "dataStructure.h"

activity::activity()
{}

activity::activity(const QString &code,const QString &name,const QString &manager, bool active, int budget ): pCode(code), pName(name), pManager(manager),pActive(active),pBudget(budget)
{}

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

activities::activities()
{

}

void activities::read(const QJsonObject &json)
{
    QJsonArray attributeArray = json["activities"].toArray();
    for(int index = 0; index < attributeArray.size(); ++index)
    {
        QJsonObject attributeObject = attributeArray[index].toObject();
        activity attributes;
        attributes.read(attributeObject);
        pAct.append(attributes);

    }

}

