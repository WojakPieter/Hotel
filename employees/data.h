#ifndef CPP_PROJECT_DATA_H
#define CPP_PROJECT_DATA_H
#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"
#include "barman.h"
#include "bodyguard.h"
#include "cook.h"
#include "maid.h"
#include "manager.h"
#include "recepcionist.h"
#include "waiter.h"

class Data
{
    std::vector<std::unique_ptr<Employee>> database;

    public:
    bool add_employee(std::string, std::string, std::string, std::string, std::string, double);
    bool remove_employee(std::string, std::string, std::string, std::string, std::string, double);
    std::unique_ptr<Employee> make_employee_pointer(std::string, std::string, std::string, std::string, std::string, double);

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