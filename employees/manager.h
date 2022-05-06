#ifndef CPP_PROJECT_MANAGER_H
#define CPP_PROJECT_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Manager : public Employee
{
    public:
    Manager(std::string, std::string, std::string, std::string, double);
    
    // void dismissEmployee();
    // void hireEmployee();
    // void changeEmployeesRate();
    // void give
    // void setEmployeeRate(double newRate);

    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate(double);
    virtual void makeRoster(Date);

    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif