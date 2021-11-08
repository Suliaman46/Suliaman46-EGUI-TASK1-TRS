#include<QString>
#include<QDate>
#ifndef SESSIONUSER_H
#define SESSIONUSER_H


class sessionUser
{
public:
    static sessionUser& getInstance(){
        static sessionUser theInstance;
        return theInstance;
    }

    void setUserName(const QString &name);
    QString getUserName() const;

    QDate getDate() const;
    void setDate(const QDate argDate);
private:
    sessionUser();
    QString userName;
    QDate date;
};

#endif // SESSIONUSER_H
