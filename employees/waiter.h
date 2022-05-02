#ifndef CPP_PROJECT_WAITER_H
#define CPP_PROJECT_WAITER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class waiter : public employee
{
    public:
    waiter(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    virtual double workingHours();
    virtual double salary();

    // double receipt();

    // virtual void makeRoster()=0;
    // virtual void takeVacation(date)=0;
    // virtual void removeVacation(date)=0;

};
#endif