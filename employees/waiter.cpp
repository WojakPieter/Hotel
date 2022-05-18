#include <iostream>
#include "waiter.h"
#include "employee.h"
#include <stdio.h>    
#include <algorithm>
#include <vector>
#include <stdlib.h>

Waiter::Waiter(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Waiter::working_hours()
{
    return get_working_days("waiter")*get_working_hours("waiter");
}

double Waiter::salary()
{
    return get_hourly_rate("waiter")*get_working_hours("waiter");
}

void Waiter::set_hourly_rate() {
    hourly_rate = get_hourly_rate("waiter");
}

void Waiter::make_roster(std::vector<std::pair<Date, int>> schedule){
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
    for(int i = 0; i < (get_working_days("waiter")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Waiter::bring_the_dish(){
    x += 0.4; //kwadrans na rozdanie dania do pokoju
}

std::string Waiter::get_type(){
    return "waiter";
}