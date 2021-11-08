#include "sessionuser.h"

sessionUser::sessionUser()
{

}
void sessionUser::setUserName(const QString &name)
{
    userName = name;
}

QString sessionUser::getUserName() const
{
    return userName;
}
QDate sessionUser::getDate() const
{
    return date;
}

void sessionUser::setDate(const QDate argDate)
{
    date = argDate;
}
