#include <iostream>
#include "employee.h"
#include "manager.h"
#include <algorithm>
#include <vector>

Manager::Manager(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
Employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double Manager::workingHours()
{
    return getWorkingDays("manager")*getWorkingHours("manager");
}

double Manager::salary()
{
    return getHourlyRate("manager")*getWorkingHours("manager");
}

void Manager::setHourlyRate() {
    hourlyRate = getHourlyRate("manager");
}

void Manager::makeRoster(std::vector<std::pair<Date, int>> schedule){
    roster = {};
    std::vector<std::pair<Date, int>> new_schedule = schedule;
    for(unsigned int i = 0; i < freeDays.size(); i++)
        new_schedule.erase(std::find(new_schedule.begin(), new_schedule.end(), freeDays[i]));

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("manager")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void dismissEmployee(std::string PESEL, std::vector <employee> employees){
    for(unsigned int i = 0; i < employees.size(); i++)
        if (PESEL == employees[i].get_PESEL())
        {
            employees.erase(employees.begin() + i);
            break;
        }
}

void hireEmployee(Employee new_employee, std::vector <employee> employees)
{
    for (unsigned int i = 0; i < employees.size(); i++)
        if (new_employee.getPESEL() == employees[i].get_PESEL())
            return;
    employees.push_back(new_employee);
}

void setEmployeeRate(std::string PESEL, double newRate, std::vector <employee> employees){
    for(unsigned int i = 0; i < employees.size(); i++)
        if (PESEL == employees[i].get_PESEL())
            employees[i].sethourlyRate(newRate);

}

std::string Manager::get_type(){
    return "manager";
}