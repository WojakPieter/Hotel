#ifndef CPP_PROJECT_MANAGER_H
#define CPP_PROJECT_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class manager : public employee
{
    public:
    manager(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    // void dismissEmployee();
    // void hireEmployee();
    // void changeEmployeesRate();
    // void give

    void setEmployeeRate(double newRate);
    virtual double workingHours();
    virtual double salary();


    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif