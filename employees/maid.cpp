<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
#include "maid.h"
#include <algorithm>

Maid::Maid(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{type = "maid";}


void Maid::make_roster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(auto& parr : new_schedule)
    {
        if(parr.second == 3) new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), parr));
    }
    for(unsigned int i = 0; i < free_days.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), free_days[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (get_working_days("maid")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}


void Maid::tidy_room(int number) {
    x += 1;
}

=======
#include <iostream>
#include <string>
#include <vector>
#include "maid.h"
#include <algorithm>

Maid::Maid(std::string first_name, std::string last_name, std::string email_adress, std::string PESEL, double hourly_rate):
Employee(first_name, last_name, email_adress, PESEL, hourly_rate)
{type = "maid";}


void Maid::make_roster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    auto pend = std::remove_if(schedule.begin(), schedule.end(), [&](std::pair<Date, int> changes){return changes.second == 3;});
    schedule.erase(pend, schedule.end());
    for(unsigned int i = 0; i < free_days.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), free_days[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (get_working_days("maid")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}


void Maid::tidy_room() {
    x += 1;
}

>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
