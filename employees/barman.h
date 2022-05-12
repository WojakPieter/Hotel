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
    virtual void setHourlyRate();
    virtual void makeRoster(Date);

    void addDrink(std::string, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void changeDrinkPrice(std::string, double, double, Menu);
    void removeDrink(std::string, Menu);
    void doDrink(std::string);
    

    virtual void takeVacation(date);
    virtual void removeVacation(date);

};
#endif