#ifndef CPP_PROJECT_MENU_H
#define CPP_PROJECT_MENU_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

class menu
{
    std::string name;
    std::vector<std::pair<std::string, double>> dishes;
    std::vector<std::pair<std::string, double>> drinks;

    public:
    menu(std::string, std::vector<std::pair<std::string, double>>, std::vector<std::pair<std::string, double>>);
    
    std::string getName();
    void setName(std::string);

    void addDish(std::string, double);
    void addDrink(std::string, double);
    void removeDish(std::string);
    void removeDrink(std::string);
    void changeDish(std::string, double);
    void changeDrink(std::string, double);

    int countDishes();
    int countDrinks();

    double findPrize(std::string);
};
#endif