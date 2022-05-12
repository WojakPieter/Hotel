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
    return getWorkingDays("recepcionist")*getWorkingHours("recepcionist");
}

double Recepcionist::salary()
{
    return getHourlyRate("recepcionist")*getWorkingHours("recepcionist");
}

void Recepcionist::setHourlyRate() {
    hourlyRate = getHourlyRate("recepcionist");
}

void Recepcionist::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, (rand() % 3)+1);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("recepcionist")-1); i++){
        roster.push_back(schedule[i]);
    }
}

void Recepcionist::book_room(Room room, Date first_date, Date last_date, Guest guest){
    while(first_date<=last_date)
    {
        room.add_day(first_date);
        first_date += 1;
        // dodac funkcje
    }
    guest.set_room_number(room.get_number());
    guest.set_receipt(room.get_price()*(last_date-first_date+1) + guest.get_receipt());
}