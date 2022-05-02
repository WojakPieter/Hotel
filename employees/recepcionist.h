#ifndef CPP_PROJECT_RECEPCIONIST_H
#define CPP_PROJECT_RECEPCIONIST_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class recepcionist : public employee
{
    public:
    recepcionist(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    virtual double workingHours();
    virtual double salary();

    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif