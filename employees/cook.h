<<<<<<< HEAD
#ifndef CPP_PROJECT_COOK_H
#define CPP_PROJECT_COOK_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../menu.h"
#include "../ingredient.h"

class Cook : public Employee
{
    public:
    Cook(std::string, std::string, std::string, std::string, double);
    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void add_dish(std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void change_dish_price(std::string, double, double, Menu);
    void remove_dish(std::string, Menu);
    void do_dish(std::string, Menu);
};
#endif
=======
#ifndef CPP_PROJECT_COOK_H
#define CPP_PROJECT_COOK_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../menu.h"
#include "../ingredient.h"

class Cook : public Employee
{
    public:
    Cook(std::string, std::string, std::string, std::string, double);
    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void add_dish(std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void change_dish_price(std::string, double, double, Menu);
    void remove_dish(std::string, Menu);
    void do_dish(std::string, Menu);
};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
