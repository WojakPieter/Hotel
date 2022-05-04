#ifndef CPP_PROJECT_MAID_H
#define CPP_PROJECT_MAID_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
// #include "Room.h"

class maid : public employee
{
    public:
    maid(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate(double);

    // void tidyRoom(int number);

    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif