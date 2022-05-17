#ifndef CPP_PROJECT_BARMAN_H
#define CPP_PROJECT_BARMAN_H
#include <iostream>
#include <string>
#include "ingredient.h"
#include "menu.h"
#include <vector>
#include "employee.h"

class Barman : public Employee
{
    public:
    Barman(std::string, std::string, std::string, std::string, double);
    
    virtual double workingHours();
    virtual double salary();
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);

    void addDrink(std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void changeDrinkPrice(std::string, double, double, Menu);
    void removeDrink(std::string, Menu);
    void doDrink(std::string, Menu);

    virtual std::string get_type();
};
#endif