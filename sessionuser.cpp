#include "sessionuser.h"

sessionUser::sessionUser()
{

}

const QString &sessionUser::getManagerReportMonth() const
{
    return managerReportMonth;
}

void sessionUser::setManagerReportMonth(const QString &newManagerReportMonth)
{
    managerReportMonth = newManagerReportMonth;
}

const QString &sessionUser::getTargetUserForManagerTable() const
{
    return targetUserForManagerTable;
}

void sessionUser::setTargetUserForManagerTable(const QString &newTargetUserForManagerTable)
{
    targetUserForManagerTable = newTargetUserForManagerTable;
}

bool sessionUser::getIsManager() const
{
    return isManager;
}

void sessionUser::setIsManager(bool newIsManager)
{
    isManager = newIsManager;
}

const QString &sessionUser::getCodeManager() const
{
    return codeManager;
}

void sessionUser::setCodeManager(const QString &newCodeManager)
{
    codeManager = newCodeManager;
}

int sessionUser::getTotalDailyTime() const
{
    return totalDailyTime;
}

void sessionUser::setTotalDailyTime(int newTotalDailyTime)
{
    totalDailyTime = newTotalDailyTime;
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

int sessionUser::getRowSelected() const
{
    return rowSelected;
}

void sessionUser::setRowSelected(int rowNum)
{
    rowSelected = rowNum;
}
