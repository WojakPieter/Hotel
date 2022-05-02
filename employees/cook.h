#ifndef CPP_PROJECT_COOK_H
#define CPP_PROJECT_COOK_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class cook : public employee
{
    public:
    cook(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    virtual double workingHours();
    virtual double salary();

    // void addDish(std::string name, double prize);
    // void removeDish(std::string name);
    // void changeNameOfDish(std::string newName);
    // void changePrize(double newPrize);

    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif