#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employees/employee.h"


class Data
{
    std::vector<std::unique_ptr<Employee>> database;

    public:
    bool add_employee(std::unique_ptr<Employee>);
    bool remove_employee(std::unique_ptr<Employee>);

    int get_size();
    double working_hours(std::string);
    double salary(std::string);
    bool print_employee(std::string);
    bool edit_employee(std::string, std::string, std::string, std::string);
    void print_rates();
    void set_employee_rate(std::string, double);
    bool employee_roster(std::string);
    bool make_employee_roster(std::string, std::vector<std::pair<Date, int>>);
    friend class Hotel;
    friend class Manager;
};

#endif
