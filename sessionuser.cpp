#include "sessionuser.h"

sessionUser::sessionUser()
{

}

const QStringList &sessionUser::getCodeInSelectedMonth() const
{
    return codeInSelectedMonth;
}

const QStringList &sessionUser::getCodeManager() const
{
    return codeManager;
}

void sessionUser::setCodeManager(const QStringList &newCodeManager)
{
    codeManager = newCodeManager;
}

void sessionUser::appendCodeManager(const QString &code)
{
    codeManager.append(code);
}

void sessionUser::appendToCodeInSelectedMonth(const QString &code)
{
    codeInSelectedMonth.append(code);
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
