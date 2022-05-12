#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"

class Data
{
    std::vector<std::unique_ptr<Employee>> database;

    public:
    bool add_employee(std::unique_ptr<Employee>);
    bool remove_employee(std::unique_ptr<Employee>);

    int get_size();
    double working_hours(std::string PESEL);
    double salary(std::string PESEL);
    bool print_employee(std::string);
    bool edit_employee(std::string, std::string, std::string, std::string);
    void print_rates();
    bool employee_roster(std::string pesel);
    bool make_employee_roster(std::string, Date);
};

#endif