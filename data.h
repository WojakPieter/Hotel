#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"

class data
{
    std::vector<std::unique_ptr<employee>> database;

    public:
    void add_employee(std::unique_ptr<employee>);
    void remove_employee(std::unique_ptr<employee>);

    int get_size();
    double working_hours(std::string PESEL);
    double salary(std::string PESEL);
    void print_rates();
};

#endif