#include <iostream>
#include "employee.h"
#include "../menu.h"
#include "../ingredient.h"
#include <algorithm>
#include <vector>
#include "cook.h"

Cook::Cook(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Cook::workingHours()
{
    return getWorkingDays("cook")*getWorkingHours("cook");
}

double Cook::salary()
{
    return getHourlyRate("cook")*getWorkingHours("cook");
}

void Cook::setHourlyRate() {
    hourlyRate = getHourlyRate("cook");
}

void Cook::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < freeDays.size(); i++){
        for(unsigned int j = 0; j < new_schedule.size(); j++)
        {
            if (new_schedule[j].second == freeDays[i].second && new_schedule[j].first == freeDays[i].first)
            {
                new_schedule.erase(new_schedule.begin() + j);
                break;
            }
        }
    }

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("cook")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Cook::addDish(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens, Menu menu){
    Dish new_drink(name, price, preparation_cost, preparation_time, ingredients, allergens);
    menu.add_food(new_drink);
}

void Cook::changeDishPrice(std::string name, double new_price, double new_preparation_cost, Menu menu){
    menu.change_food_price(name, new_price, new_preparation_cost);
}

void Cook::removeDish(std::string name, Menu menu){
    menu.remove_drink(name);
}

void Cook::doDish(std::string name, Menu menu){
    double time = menu.find_preparation_time(name);
    x += time;
    // trzeba sprawdzic w Hotelu czy jest mniejsza niz zmiana
}

std::string Cook::get_type(){
    return "cook";
}
