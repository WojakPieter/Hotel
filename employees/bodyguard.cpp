#include <iostream>
#include "employee.h"
#include <algorithm>
#include <vector>
#include "bodyguard.h"
#include "guest.h"

Bodyguard::Bodyguard(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Bodyguard::working_hours()
{
    return get_working_days("bodyguard")*get_working_hours("bodyguard");
}

double Bodyguard::salary()
{
    return get_hourly_rate("bodyguard")*get_working_hours("bodyguard");
}

void Bodyguard::set_hourly_rate() {
    hourly_rate = get_hourly_rate("bodyguard");
}

void Bodyguard::make_roster(std::vector<std::pair<Date, int>> schedule){
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
    for(int i = 0; i < (get_working_days("bodyguard")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

std::string Bodyguard::get_type(){
    return "bodyguard";
}