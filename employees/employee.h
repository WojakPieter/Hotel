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
    std::vector<std::pair<Date, int>> roster;
    std::vector<Date> freeDays;


    public:
    Employee(std::string, std::string, std::string, std::string, double);
    // ~employee();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAdress() const;
    std::string getPESEL() const;
    void printRoster();
    double getHourlyRate() const;
    void setName(std::string, std::string);
    void setEmailAdress(std::string);
    void setPESEL(std::string);
    virtual void setHourlyRate(double) = 0;
    virtual double workingHours() = 0;
    virtual double salary() = 0;
    virtual void makeRoster(Date)=0;
    // virtual void takeVacation(Date)=0;
    // virtual void removeVacation(Date)=0;

    bool operator==(const Employee& second_employee)
    {
        return(PESEL == second_employee.PESEL);
    }
};
#endif