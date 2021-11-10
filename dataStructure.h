#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDate>
#include <QDir>
#include "sessionuser.h"
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

    QStringList getSubactivities() const;

    void setSubactivities(const QStringList &newSubactivities);

private:
    QString pCode;
    QString pManager;
    QString pName;
    bool pActive;
    int pBudget;
    QStringList subactivities;


};

class activities
{
public:
    activities();
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
    void create(const QString &code,const QString &name,const QString &manager, bool active, int budget,const QStringList& newSubactivities );
    int sizeActivities();
    QStringList subcodeList(const QString code);
    bool getActiveStatus(const QString& code);
    void setActiveStatus(const QString& code,bool status);

    const QList<activity*>& getActivitiesList() const;

private:
    QList<activity*> pActivitiesList;
};



class entry{

public:
    entry();
    entry(const QString &code,const QString &subcode,const QString &description,int time, const QDate &date);

    void read(const QJsonObject& json);
    void write(QJsonObject &json) const;
    QVariant getData(int index) const;
    QDate getDate() const;

    void setPCode(const QString &newPCode);
    void setPSubcode(const QString &newPSubcode);
    void setPDescription(const QString &newPDescription);
    void setPTime(int newPTime);

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
    const QString &getPCode() const;
    void setPCode(const QString &newPCode);
    int getPTime() const;
    void setPTime(int newPTime);

private:
    QString pCode;
    int pTime;
};

class month
{
public:
    month() {}
    month(QString monthYear );
    void read(const QJsonObject & json);
    void write( QJsonObject & json) const;
    QDate pMonthYear;
    QString pMY;
    QVariant getData(int row, int column, QDate date) const;
    int getNumEntries() const;

    const QList<entry*>* getEntries() const;
    const QList<accepted*>* getAccepted() const;

    void addEntry(const QString &code, const QString &subcode, int time, const QString &description);
    void editEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    void removeEntry();



    bool getPFrozen() const;
    void setPFrozen(bool newPFrozen);

private:

    bool pFrozen;
    QList<entry*> pEntries;
    QList<accepted*> pAcceptedTimes;

};


class user
{
public:
    user();
    user(QString name, QString dir);
    void read();
    void write();
    QString getName() const;
//    QVariant getData(int row, int column, QDate date) const;
    int getNumEntries(QString monthYear) const;

    void addEntry(const QString &code, const QString &subcode, int time, const QString &description);

    const QList<entry*> *getEntries(QString targetMonthYear) const;
    const QList<accepted*>* getAccepted(QString targetMonthYear) const;


    void editEntry(const QString&code, const QString &subcode ,int time,const QString &description);
    void removeEntry();

    bool isMonthFrozen(const QString& monthYear);

private:
    QString pName;
    QDir pDirectory;
    QList<month*> monthlyReports;


};




#endif // DATASTRUCTURE_H
