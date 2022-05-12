#include <iostream>
#include "employee.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include "barman.h"
#include "menu.h"

Barman::Barman(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Barman::workingHours()
{
    return getWorkingDays("barman")*getWorkingHours("barman");
}

double Barman::salary()
{
    return getHourlyRate("barman")*getWorkingHours("barman");
}

void Barman::setHourlyRate() {
    hourlyRate = getHourlyRate("barman");
}

void Barman::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, 3);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("barman")-1); i++){
        roster.push_back(schedule[i]);
    }
}

void Barman::addDrink(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens, Menu menu){
    Dish new_drink(name, price, preparation_cost, preparation_time, ingredients, allergens);
    menu.add_drink(new_drink);
}

void Barman::changeDrinkPrice(std::string name, double new_price, double new_preparation_cost, Menu menu){
    menu.change_drink_price(name, new_price, new_preparation_cost);
}

void Barman::removeDrink(std::string name, Menu menu){
    menu.remove_drink(name);
}

void Barman::doDrink(std::string name){
    double time = menu.findPreparationTime(name);
    x += time;
    // trzeba sprawdzic w Hotelu czy jest mniejsza niz zmiana 
}