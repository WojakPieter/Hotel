#ifndef CPP_PROJECT_MANAGER_H
#define CPP_PROJECT_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "data.h"
#include <memory>
#include "employee.h"

class Manager : public Employee
{
    public:
    Manager(std::string, std::string, std::string, std::string, double);
    
    // void dismissEmployee(std::string, std::string, std::string, std::string, std::string, double, Data);
    // // data - przekazac
    // void hireEmployee(std::string, std::string, std::string, std::string, std::string, double, Data);
    // void setEmployeeRate(std::string, double, Data);

    virtual double working_hours();
    virtual double salary();
    virtual void set_hourly_rate();
    virtual void make_roster(std::vector<std::pair<Date, int>>);

    virtual std::string get_type();
};
#endif