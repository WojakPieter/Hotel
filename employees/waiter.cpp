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
    int days = roster.size();
    return 8*days;
}

double Waiter::salary()
{
    return hourlyRate*workingHours();
}

void Waiter::setHourlyRate(double newRate) {
    if (newRate > 0)
        hourlyRate = newRate;
    else
        throw std::range_error("Stawka godzinowa musi byc wieksza od zera");
}

void Waiter::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, rand() % 3);
        schedule.push_back(relay);
        date1 += 1;
    }
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < 25; i++){
        roster.push_back(schedule[i]);
    }
}