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
    virtual void setHourlyRate();
    virtual void makeRoster(std::vector<std::pair<Date, int>>);

    void addDish(std::string, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void changeDishPrice(std::string, double, double, Menu);
    void removeDish(std::string, Menu);
    void doDish(std::string);
};
#endif