#include <iostream>
#include "recepcionist.h"
#include <algorithm>
#include <vector>
#include "employee.h"
#include "room.h"

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
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("recepcionist")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void Recepcionist::book_room(Room room, Date first_date, Date last_date, Guest guest){
    while(first_date<=last_date)
    {
        room.add_reserved_day(first_date);
        first_date += 1;
    }
    guest.set_room_number(room.get_number());
    guest.set_receipt(room.get_price()*(last_date-first_date+1) + guest.get_receipt());
}