#include <iostream>
#include "waiter.h"
#include "employee.h"
#include <stdio.h>    
#include <algorithm>
#include <vector>
#include <stdlib.h>

Waiter::Waiter(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Waiter::workingHours()
{
    return getWorkingDays("waiter")*getWorkingHours("waiter");
}

double Waiter::salary()
{
    return getHourlyRate("waiter")*getWorkingHours("waiter");
}

void Waiter::setHourlyRate() {
    hourlyRate = getHourlyRate("waiter");
}

void Waiter::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < freeDays.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("waiter")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Waiter::bring_the_dish(){
    x += 0.4; //kwadrans na rozdanie dania do pokoju
}
