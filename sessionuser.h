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

    int getRowSelected() const;
    void setRowSelected(int rowNum);
private:
    sessionUser();
    QString userName;
    QDate date;
    int rowSelected;
};

#endif // SESSIONUSER_H
