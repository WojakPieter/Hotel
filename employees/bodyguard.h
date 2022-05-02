#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
// #include "guest.h"

class bodyguard : public employee
{
    public:
    bodyguard(std::string, std::string, std::string, std::string, double, std::vector<std::pair<Date, int>>, std::vector<Date>);
    
    virtual double workingHours();
    virtual double salary();

    // void removeGuest(guest);

    // virtual void makeRoster();
    // virtual void takeVacation(date);
    // virtual void removeVacation(date);

};
#endif