#include <iostream>
#include "recepcionist.h"
#include <algorithm>
#include <vector>
#include "employee.h"
#include "room.h"

Recepcionist::Recepcionist(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Recepcionist::working_hours()
{
    return get_working_days("recepcionist")*get_working_hours("recepcionist");
}

double Recepcionist::salary()
{
    return get_hourly_rate("recepcionist")*get_working_hours("recepcionist");
}

void Recepcionist::set_hourly_rate() {
    hourly_rate = get_hourly_rate("recepcionist");
}

void Recepcionist::make_roster(std::vector<std::pair<Date, int>> schedule){
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
    for(int i = 0; i < (get_working_days("recepcionist")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Recepcionist::book_room(int room_number, Date first_date, Date last_date, Guest guest){
    ;
}

std::string Recepcionist::get_type(){
    return "recepcionist";
}