#include <iostream>
#include "employee.h"
#include "ingredient.h"
#include "menu.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include "barman.h"

Barman::Barman(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Barman::working_hours()
{
    return get_working_days("barman")*get_working_hours("barman");
}

double Barman::salary()
{
    return get_hourly_rate("barman")*get_working_hours("barman");
}

void Barman::set_hourly_rate() {
    hourly_rate = get_hourly_rate("barman");
}

void Barman::make_roster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < free_days.size(); i++)
        for(unsigned int j = 0; j < new_schedule.size(); j++)
        {
            if (new_schedule[j].second == free_days[i].second && new_schedule[j].first == free_days[i].first)
            {
                new_schedule.erase(new_schedule.begin() + j);
                break;
            }
        }
    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (get_working_days("barman")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Barman::add_drink(std::string name, double price, double preparation_cost, double preparation_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens, Menu menu){
    Dish new_drink(name, price, preparation_cost, preparation_time, ingredients, allergens);
    menu.add_drink(new_drink);
}

void Barman::change_drink_price(std::string name, double new_price, double new_preparation_cost, Menu menu){
    menu.change_drink_price(name, new_price, new_preparation_cost);
}

void Barman::remove_drink(std::string name, Menu menu){
    menu.remove_drink(name);
}

void Barman::do_drink(std::string name, Menu menu){
    double time = menu.find_preparation_time(name);
    x += time;
    // trzeba sprawdzic w Hotelu czy jest mniejsza niz zmiana 
}

std::string Barman::get_type(){
    return "barman";
}