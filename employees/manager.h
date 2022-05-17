#ifndef CPP_PROJECT_MANAGER_H
#define CPP_PROJECT_MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "../data.h"
#include <memory>
#include "employee.h"

class Manager : public Employee
{
    public:
    Manager(std::string, std::string, std::string, std::string, double);

    void dismissEmployee(std::unique_ptr<Employee>, Data);
    // data - przekazac
    void hireEmployee(std::unique_ptr<Employee>, Data);
    void setEmployeeRate(std::string, double, Data);

    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);

    virtual std::string get_type();
};
#endif
