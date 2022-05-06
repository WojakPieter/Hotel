#ifndef CPP_PROJECT_RECEPCIONIST_H
#define CPP_PROJECT_RECEPCIONIST_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Recepcionist : public Employee
{
    public:
    Recepcionist(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate(double);
    virtual void makeRoster(Date);

    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif