#ifndef CPP_PROJECT_MENU_H
#define CPP_PROJECT_MENU_H
#include <iostream>
#include <string>
#include <vector>
#include "dish.h"

class Menu
{
    std::string name;
    std::vector<Dish> food;
    std::vector<Dish> drinks;

    public:
    Menu(std::string, std::vector<Dish>, std::vector<Dish>);
    
    std::string get_name();
    void set_name(std::string);

    void add_food(Dish);
    void add_drink(Dish);
    void remove_food(std::string);
    void remove_drink(std::string);
    void change_food_price(std::string, double, double);
    void change_drink_price(std::string, double, double);

    int count_food();
    int count_drinks();

    double find_price(std::string);
    double find_preparation_cost(std::string);
    double find_preparation_time(std::string name);
};
#endif