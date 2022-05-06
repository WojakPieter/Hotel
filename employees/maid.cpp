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
    int days = roster.size();
    return 9*days;
}

double Maid::salary()
{
    return hourlyRate*workingHours();
}

void Maid::setHourlyRate(double newRate) {
    if (newRate > 0)
        hourlyRate = newRate;
    else
        throw std::range_error("Stawka godzinowa musi byc wieksza od zera");
}

void Maid::makeRoster(Date date1){
    // std::vector<int>zmiany = {1, 2, 3};
    int partOfDay = 1;
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, partOfDay);
        schedule.push_back(relay);
        date1 += 1;
    }
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < 25; i++){
        roster.push_back(schedule[i]);
    }
}