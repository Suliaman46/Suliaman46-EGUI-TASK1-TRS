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
    int getTotalDailyTime() const;
    void setTotalDailyTime(int newTotalDailyTime);

    bool getIsManager() const;
    void setIsManager(bool newIsManager);



    const QString &getTargetUserForManagerTable() const;
    void setTargetUserForManagerTable(const QString &newTargetUserForManagerTable);

    const QString &getManagerReportMonth() const;
    void setManagerReportMonth(const QString &newManagerReportMonth);

    const QStringList &getCodeManager() const;
    void setCodeManager(const QStringList &newCodeManager);

    void appendToCodeInSelectedMonth(const QString& code);

    const QStringList &getCodeInSelectedMonth() const;

private:
    sessionUser();
    QString userName;
    QDate date;
    int rowSelected;
    int totalDailyTime;
    bool isManager;
    QStringList codeManager; // Codes of project Managed by Logged in User
    QStringList codeInSelectedMonth; // Codes of project Managed by Loogged in User in the Month chosen in Main Manager window
    QString targetUserForManagerTable;
    QString managerReportMonth;
};

#endif // SESSIONUSER_H
