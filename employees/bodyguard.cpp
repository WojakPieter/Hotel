#include <iostream>
#include "recepcionist.h"
#include "employee.h"
#include <algorithm>
#include <vector>
#include "bodyguard.h"
#include "../guest.h"

Bodyguard::Bodyguard(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Bodyguard::workingHours()
{
    return getWorkingDays("bodyguard")*getWorkingHours("bodyguard");
}

double Bodyguard::salary()
{
    return getHourlyRate("bodyguard")*getWorkingHours("bodyguard");
}

void Bodyguard::setHourlyRate() {
    hourlyRate = getHourlyRate("bodyguard");
}

void Bodyguard::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < freeDays.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("bodyguard")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

std::string Bodyguard::get_type(){
    return "bodyguard";
}
