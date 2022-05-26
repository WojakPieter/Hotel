<<<<<<< HEAD
#include <iostream>
#include "employee.h"
#include <algorithm>
#include <vector>
#include "bodyguard.h"
#include "../guest.h"

Bodyguard::Bodyguard(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{{type = "bodyguard";}}



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

=======
#include <iostream>
#include "employee.h"
#include <algorithm>
#include <vector>
#include "bodyguard.h"
#include "../guest.h"

Bodyguard::Bodyguard(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{{type = "bodyguard";}}



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

>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
