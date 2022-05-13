#ifndef CPP_PROJECT_MAID_H
#define CPP_PROJECT_MAID_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Maid : public Employee
{
    public:
    Maid(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);

    void tidyRoom(Room room);
};
#endif