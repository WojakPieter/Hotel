#ifndef CPP_PROJECT_EMPLOYEE_H
#define CPP_PROJECT_EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

class Employee
{
    protected:
    std::string firstName;
    std::string lastName;
    std::string emailAdress;
    std::string PESEL;
    double hourlyRate;
    double x;
    std::vector<std::pair<Date, int>> roster;
    std::vector<std::pair<Date, int>> freeDays;


    public:
    Employee(std::string, std::string, std::string, std::string, double);
    virtual ~Employee();

    double getWorkedHours() const;
    void setWorkedHours(double);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAdress() const;
    std::string getPESEL() const;
    double gethourlyRate() const;
    void sethourlyRate(double);
    void printRoster();
    double getHourlyRate(std::string) const;
    int getWorkingDays(std::string) const;
    int getWorkingHours(std::string) const;
    void setName(std::string, std::string);
    void setEmailAdress(std::string);
    void setPESEL(std::string);
    virtual void setHourlyRate() = 0;
    virtual double workingHours() = 0;
    virtual double salary() = 0;
    virtual void makeRoster(std::vector<std::pair<Date, int>>)=0;
    void start_day();
    void takeVacation(Date);
    void removeVacation(Date);
    virtual std::string get_type()=0;

    bool operator==(const Employee& second_employee)
    {
        return(PESEL == second_employee.PESEL);
    }
};
#endif