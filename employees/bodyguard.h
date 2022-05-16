#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../guest.h"

class Bodyguard : public Employee
{
    public:
    Bodyguard(std::string, std::string, std::string, std::string, double);

    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);
    virtual std::string get_type();

    void removeGuest(Guest, std::vector<Guest>);
};
#endif
