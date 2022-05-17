#include <iostream>
#include "employee.h"
#include "manager.h"
#include <algorithm>
#include <memory>
#include "../data.h"
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
        for(unsigned int j = 0; j < new_schedule.size(); j++)
        {
            if (new_schedule[j].second == freeDays[i].second && new_schedule[j].first == freeDays[i].first)
            {
                new_schedule.erase(new_schedule.begin() + j);
                break;
            }
        }

    std::random_shuffle(new_schedule.begin(), new_schedule.end());
    for(int i = 0; i < (getWorkingDays("manager")-1); i++){
        roster.push_back(new_schedule[i]);
    }
}

void dismissEmployee(std::unique_ptr<Employee> ptr, Data data){
    data.remove_employee(std::move(ptr));
}

void hireEmployee(std::unique_ptr<Employee> ptr, Data data)
{
    data.add_employee(std::move(ptr));
}

void setEmployeeRate(std::string PESEL, double newRate, Data data){
    data.set_employee_rate(PESEL, newRate);
}

std::string Manager::get_type(){
    return "manager";
}
