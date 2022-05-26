<<<<<<< HEAD
#ifndef CPP_PROJECT_BARMAN_H
#define CPP_PROJECT_BARMAN_H
#include <iostream>
#include <string>
#include "../ingredient.h"
#include "../menu.h"
#include <vector>
#include "employee.h"

class Barman : public Employee
{
    public:
    Barman(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void add_drink(std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void change_drink_price(std::string, double, double, Menu);
    void remove_drink(std::string, Menu);
    void do_drink(std::string, Menu);

};
#endif
=======
#ifndef CPP_PROJECT_BARMAN_H
#define CPP_PROJECT_BARMAN_H
#include <iostream>
#include <string>
#include "../ingredient.h"
#include "../menu.h"
#include <vector>
#include "employee.h"

class Barman : public Employee
{
    public:
    Barman(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void add_drink(std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>, Menu);
    void change_drink_price(std::string, double, double, Menu);
    void remove_drink(std::string, Menu);
    void do_drink(std::string, Menu);

};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
