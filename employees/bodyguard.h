#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Bodyguard : public Employee
{
    public:
    Bodyguard(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(Date);

    void removeGuest(guest, std::vector<guest>);

    virtual void takeVacation(date);
    virtual void removeVacation(date);

};
#endif