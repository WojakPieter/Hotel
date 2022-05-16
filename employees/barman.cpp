#include <iostream>
#include "employee.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include "barman.h"
#include "../menu.h"

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

void Barman::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    auto pend = std::remove_if(schedule.begin(), schedule.end(), [&](std::pair<double, double> changes){return changes.second == 3;});
    schedule.erase(pend, schedule.end());
    for(unsigned int i = 0; i < freeDays.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("barman")-1); i++){
        roster.push_back(new_schedule[i]);
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

std::string Barman::get_type(){
    return "barman";
}
