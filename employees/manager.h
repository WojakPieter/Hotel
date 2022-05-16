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

    void dismissEmployee(std::string, std::vector<Employee>);
    //void hireEmployee(Employee, std::vector<Employee>);
    void setEmployeeRate(std::string, double, std::vector<Employee>);

    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);

    virtual std::string get_type();
};
#endif
