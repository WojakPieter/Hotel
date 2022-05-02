#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "menu.h"

menu::menu(std::string name1, std::vector<std::pair<std::string, double>> dishes1, std::vector<std::pair<std::string, double>> drinks1)
{
    name = name1;
    dishes = dishes1;
    drinks = drinks1;
}

std::string menu::getName(){
    return name;
}

void menu::setName(std::string newName){
    name = newName;
}

void menu::addDish(std::string name, double prize){
    for(unsigned int i = 0; i < dishes.size(); i++)
        if (name == dishes[i].first)
            return;
    std::pair <std::string, double> dish(name, prize);
    dishes.push_back(dish);
}

void menu::addDrink(std::string name, double prize){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].first)
            return;
    std::pair <std::string, double> drink(name, prize);
    drinks.push_back(drink);
}

void menu::removeDish(std::string name){
    for(unsigned int i = 0; i < dishes.size(); i++)
        if (name == dishes[i].first)
        {
            dishes.erase(dishes.begin() + i);
            break;
        }
}

void menu::removeDrink(std::string name){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].first)
        {
            drinks.erase(drinks.begin() + i);
            break;
        }
}

void menu::changeDish(std::string name, double newPrize){
    for(unsigned int i = 0; i < dishes.size(); i++)
        if (name == dishes[i].first)
        {
            dishes[i].second = newPrize;
            break;
        }
}

void menu::changeDrink(std::string name, double newPrize){
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].first)
        {
            drinks[i].second = newPrize;
            break;
        }
}

int menu::countDishes(){
    return dishes.size();
}

int menu::countDrinks(){
    return drinks.size();
}


double menu::findPrize(std::string name){
    for(unsigned int i = 0; i < dishes.size(); i++)
        if (name == dishes[i].first)
            return dishes[i].second;
    
    for(unsigned int i = 0; i < drinks.size(); i++)
        if (name == drinks[i].first)
            return drinks[i].second;
}
