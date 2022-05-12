#include <iostream>
#include "employee.h"
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

void Cook::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, (rand() % 2)+1);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("cook")-1); i++){
        roster.push_back(schedule[i]);
    }
}

void Cook::addDish(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens, Menu menu){
    Dish new_dish(name, price, preparation_cost, preparation_time, ingredients, allergens);
    menu.add_food(new_drink);
}

void Cook::changeDishPrice(std::string name, double new_price, double new_preparation_cost, Menu menu){
    menu.change_food_price(name, new_price, new_preparation_cost);
}

void Cook::removeDish(std::string name, Menu menu){
    menu.food(name);
}

void Cook::doDish(std::string name){
    double time = menu.findPreparationTime(name);
    x += time;
    // trzeba sprawdzic w Hotelu czy jest mniejsza niz zmiana 
}