#ifndef CPP_PROJECT_BARMAN_H
#define CPP_PROJECT_BARMAN_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class barman : public employee
{
    public:
    barman(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    virtual double workingHours();
    virtual double salary();

    // void addDrink(std::string, double);
    // void changeDrink(std::string, double);
    // void removeDrink(std::string);
    // double receipt();

    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif