#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDate>
#include <QDir>

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

class activity
{
public:
    activity();
    activity(const QString &code,const QString &name,const QString &manager, bool active, int budget);

    QString code() const;
    void setCode(const QString &code);

    QString manager() const;
    void setManager(const QString &manager);

    QString name() const;
    void setName(const QString &name);

    int budget() const;
    void setBudget(int budget);

    bool active() const;
    void setActive(bool active) ;

    void read(const QJsonObject& json);
    void write(QJsonObject &json) const;


private:
    QString pCode;
    QString pManager;
    QString pName;
    bool pActive;
    int pBudget;
    QList<QString> subactivities;


};

class activities
{
public:
    activities();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void create(const QString &code,const QString &name,const QString &manager, bool active, int budget);
    int sizeActivities();
    QVariant getData(int row, int column);

private:
    QList<activity> pActivitiesList;
};



class entry{

public:
    entry();
    entry(const QString &code,const QString &subcode,const QString &description,int time, const QDate &date);

    void read(const QJsonObject& json);
    void write(QJsonObject &json) const;
    QVariant getData(int index);

private:
    QString pCode;
    QString pSubcode;
    QString pDescription;
    int pTime;
    QDate pDate;

};


class accepted
{
public:
    accepted() {}
    void read(const QJsonObject & json);
    void write( QJsonObject & json) const;
private:
    QString pCode;
    int pTime;
};

//// MONTH AND ACTIVITIES ARE VIABLE OPTIONS TO BE DERIVED FROM THE SAME PARENT CALSS
class month
{
public:
    month() {}
    month(QString monthYear );
    void read(const QJsonObject & json);
    void write( QJsonObject & json) const;
    QDate pMonthYear;
private:

    bool pFrozen;
    QList<entry> pEntries;
    QList<accepted> pAcceptedTimes;

};


class user
{
public:
    user();
    user(QString name, QString dir);
    void read();
    void write();
private:
    QString pName;
    QDir pDirectory;
    QList<month> monthlyReports;


};




#endif // DATASTRUCTURE_H
