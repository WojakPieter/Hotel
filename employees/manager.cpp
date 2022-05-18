#include <iostream>
#include "employee.h"
#include "manager.h"
#include <algorithm>
#include <memory>
#include "data.h"
#include <vector>

Manager::Manager(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{}

double Manager::working_hours()
{
    return get_working_days("manager")*get_working_hours("manager");
}

double Manager::salary()
{
    return get_hourly_rate("manager")*get_working_hours("manager");
}

void Manager::set_hourly_rate() {
    hourly_rate = get_hourly_rate("manager");
}

void Manager::make_roster(std::vector<std::pair<Date, int>> schedule){
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
    for(int i = 0; i < (get_working_days("manager")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

// void Manager::dismissEmployee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate, Data data){
//     data.remove_employee(type, first_name, second_name, email_adress, pesel, hourly_rate);
// }

// void Manager::hireEmployee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate, Data data)
// {
//     data.add_employee(type, first_name, second_name, email_adress, pesel, hourly_rate);
// }

// void Manager::setEmployeeRate(std::string PESEL, double newRate, Data data){
//     data.set_employee_rate(PESEL, newRate);
// }

std::string Manager::get_type(){
    return "manager";
}