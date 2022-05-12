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

void Maid::makeRoster(Date date1){
    // std::vector<int>zmiany = {1, 2, 3};
    int partOfDay = 1;
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, partOfDay);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("maid")-1); i++){
        roster.push_back(schedule[i]);
    }
}

void Maid::tidyRoom(Room room){
    room.set_parameters(false);
    x += 1;
}