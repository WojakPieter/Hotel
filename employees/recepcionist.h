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
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);
    virtual std::string get_type();

    void book_room(int, Date, Date, Guest);
};
#endif