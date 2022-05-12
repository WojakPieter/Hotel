#include <iostream>
#include "recepcionist.h"
#include "employee.h"
#include <algorithm>
#include <vector>
#include "bodyguard.h"

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

void Bodyguard::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, (rand() % 3)+1);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("bodyguard")-1); i++){
        roster.push_back(schedule[i]);
    }
}