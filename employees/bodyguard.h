#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "guest.h"

class Bodyguard : public Employee
{
    public:
    Bodyguard(std::string, std::string, std::string, std::string, double);
    
    virtual double working_hours();
    virtual double salary();
    virtual void set_hourly_rate();
    virtual void make_roster(std::vector<std::pair<Date, int>>);
    virtual std::string get_type();

    void remove_guest(Guest, std::vector<Guest>);
};
#endif