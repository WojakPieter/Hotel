#ifndef CPP_PROJECT_COOK_H
#define CPP_PROJECT_COOK_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Cook : public Employee
{
    public:
    Cook(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate(double);
    virtual void makeRoster(Date);

    // void addDish(std::string name, double prize);
    // void removeDish(std::string name);
    // void changeNameOfDish(std::string newName);
    // void changePrize(double newPrize);

    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif