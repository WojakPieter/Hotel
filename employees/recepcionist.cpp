#include <iostream>
#include "recepcionist.h"
#include <algorithm>
#include <vector>
#include "employee.h"
#include "../room.h"

Recepcionist::Recepcionist(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Recepcionist::workingHours()
{
    return getWorkingDays("recepcionist")*getWorkingHours("recepcionist");
}

double Recepcionist::salary()
{
    return getHourlyRate("recepcionist")*getWorkingHours("recepcionist");
}

void Recepcionist::setHourlyRate() {
    hourlyRate = getHourlyRate("recepcionist");
}

void Recepcionist::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < freeDays.size(); i++)
        for(unsigned int j = 0; j < new_schedule.size(); j++)
        {
            if (new_schedule[j].second == freeDays[i].second && new_schedule[j].first == freeDays[i].first)
            {
                new_schedule.erase(new_schedule.begin() + j);
                break;
            }
        }

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("recepcionist")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Recepcionist::book_room(int room_number, Date first_date, Date last_date, Guest guest){
    ;
}

std::string Recepcionist::get_type(){
    return "recepcionist";
}
