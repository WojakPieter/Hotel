#ifndef CPP_PROJECT_MAID_H
#define CPP_PROJECT_MAID_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "room.h"

class Maid : public Employee
{
    public:
    Maid(std::string, std::string, std::string, std::string, double);
    
    virtual double working_hours();
    virtual double salary();
    virtual void set_hourly_rate();
    virtual void make_roster(std::vector<std::pair<Date, int>>);
    virtual std::string get_type();

    void tidy_room();
};
#endif