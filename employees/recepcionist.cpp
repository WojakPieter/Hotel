#include <iostream>
#include "recepcionist.h"
#include <algorithm>
#include <vector>
#include "employee.h"

Recepcionist::Recepcionist(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Recepcionist::workingHours()
{
    int days = roster.size();
    return 8*days;
}

double Recepcionist::salary()
{
    return hourlyRate*workingHours();
}

void Recepcionist::setHourlyRate(double newRate) {
    if (newRate > 0)
        hourlyRate = newRate;
    else
        throw std::range_error("Stawka godzinowa musi byc wieksza od zera");
}

void Recepcionist::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, rand() % 4);
        schedule.push_back(relay);
        date1 += 1;
    }
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < 25; i++){
        roster.push_back(schedule[i]);
    }
}