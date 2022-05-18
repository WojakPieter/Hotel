#include <iostream>
#include <string>
#include <vector>
#include "maid.h"
#include <algorithm>

Maid::Maid(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Maid::working_hours()
{
    return get_working_days("maid")*get_working_hours("maid");
}

double Maid::salary()
{
    return get_hourly_rate("maid")*get_working_hours("maid");
}

void Maid::set_hourly_rate() {
    hourly_rate = get_hourly_rate("maid");
}

void Maid::make_roster(std::vector<std::pair<Date, int>> schedule) {
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
    for(int i = 0; i < (get_working_days("maid")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Maid::tidy_room() {
    x += 1;
}

std::string Maid::get_type() {
    return "maid";
}