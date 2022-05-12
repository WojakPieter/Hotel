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

void Manager::makeRoster(Date date1){
    std::vector<std::pair<Date, int>> schedule;
    for (int i = 1; i <= 31; i++){
        std::pair <Date, int> relay(date1, (rand() % 2)+1);
        schedule.push_back(relay);
        date1 += 1;
    }
    roster = {};
    std::random_shuffle(schedule.begin(), schedule.end());
    for(int i = 0; i < (getWorkingDays("manager")-1); i++){
        roster.push_back(schedule[i]);
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