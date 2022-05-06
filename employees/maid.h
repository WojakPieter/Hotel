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
    virtual void setHourlyRate(double);
    virtual void makeRoster(Date);

    // void tidyRoom(int number);

    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif