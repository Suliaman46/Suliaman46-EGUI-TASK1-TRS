#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


class activity
{
public:
    activity();
    activity(const QString &code,const QString &name,const QString &manager, bool active, int budget );

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
//    const QList<activity> & act() const;

    void read(const QJsonObject &json);
private:
    QList<activity> pAct;
};

#endif // DATASTRUCTURE_H
