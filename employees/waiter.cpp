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

void Waiter::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, (rand() % 2)+1);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("waiter")-1); i++){
        roster.push_back(schedule[i]);
    }
}

void Waiter::bring_the_dish(){
    x += 0.4; //kwadrans na rozdanie dania do pokoju
}