#ifndef CPP_PROJECT_RECEPCIONIST_H
#define CPP_PROJECT_RECEPCIONIST_H
#include <iostream>
#include <string>
#include <vector>
#include "guest.h"
#include "room.h"
#include "employee.h"

class Recepcionist : public Employee
{
    public:
    Recepcionist(std::string, std::string, std::string, std::string, double);
    
    virtual double working_hours();
    virtual double salary();
    virtual void set_hourly_rate();
    virtual void make_roster(std::vector<std::pair<Date, int>>);
    virtual std::string get_type();

    void book_room(int, Date, Date, Guest);
};
#endif