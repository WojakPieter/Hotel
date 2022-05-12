#ifndef CPP_PROJECT_WAITER_H
#define CPP_PROJECT_WAITER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Waiter : public Employee
{
    public:
    Waiter(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(Date);

    void bring_the_dish();
    // double receipt();

    // virtual void takeVacation(date)=0;
    // virtual void removeVacation(date)=0;

};
#endif