#include <iostream>
#include <string>
#include <vector>
#include "maid.h"
#include <algorithm>

Maid::Maid(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Maid::workingHours()
{
    return getWorkingDays("maid")*getWorkingHours("maid");
}

double Maid::salary()
{
    return getHourlyRate("maid")*getWorkingHours("maid");
}

void Maid::setHourlyRate() {
    hourlyRate = getHourlyRate("maid");
}

void Maid::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    auto pend = std::remove_if(schedule.begin(), schedule.end(), [&](std::pair<double, double> changes){return changes.second == 3;});
    schedule.erase(pend, schedule.end());
    for(unsigned int i = 0; i < freeDays.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("maid")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Maid::tidyRoom(Room room){
    room.set_parameters(false);
    x += 1;
}

std::string Maid::get_type(){
    return "maid";
}
