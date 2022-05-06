#ifndef CPP_PROJECT_BARMAN_H
#define CPP_PROJECT_BARMAN_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Barman : public Employee
{
    public:
    Barman(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate(double);
    virtual void makeRoster(Date);

    // void addDrink(std::string, double);
    // void changeDrink(std::string, double);
    // void removeDrink(std::string);
    // double receipt();

    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif