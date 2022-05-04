#ifndef CPP_PROJECT_EMPLOYEE_H
#define CPP_PROJECT_EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

class employee
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
    employee(std::string, std::string, std::string, std::string, double);
    // ~employee();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAdress() const;
    std::string getPESEL() const;
    double getHourlyRate() const;
    void setName(std::string, std::string);
    void setEmailAdress(std::string);
    void setPESEL(std::string);
    virtual void setHourlyRate(double) = 0;
    virtual double workingHours() = 0;
    virtual double salary() = 0;
    // virtual void makeRoster()=0;
    // virtual void takeVacation(date)=0;
    // virtual void removeVacation(date)=0;

    bool operator==(const employee& second_employee)
    {
        return(PESEL == second_employee.PESEL);
    }
};
#endif