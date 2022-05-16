#include <iostream>
#include "employee.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

Employee::Employee(std::string firstName1, std::string lastName1, std::string emailAdress1, std::string PESEL1, double hourlyRate1)
{
    firstName = firstName1;
    lastName = lastName1;
    emailAdress = emailAdress1;
    if (PESEL1.size() == 11)
        PESEL = PESEL1;
    else
        throw std::range_error("PESEL musi miec 11 cyfr");

    PESEL = PESEL1;

    if (hourlyRate1 > 0)
        hourlyRate = hourlyRate1;
    else
        throw std::range_error("Godzinowa stwka musi byc wieksza od zera");
}

void Employee::setWorkedHours(double new_hours){
    x = new_hours;
}

double Employee::getWorkedHours() const{
    return x;
}

void Employee::start_day(){
    setWorkedHours(0);
}

double Employee::gethourlyRate() const{
    return hourlyRate;
}

std::string Employee::getFirstName() const{
    return firstName;
}

std::string Employee::getLastName() const{
    return lastName;
}

std::string Employee::getEmailAdress() const{
    return emailAdress;
}

std::string Employee::getPESEL() const{
    return PESEL;
}

void Employee::sethourlyRate(double new_rate){
    if (new_rate > 0)
        hourlyRate = new_rate;
}

double Employee::getHourlyRate(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string firstLine;
    getline (outfile,firstLine);
    std::string employee;
    double HourlyRate;
    int workingDays, workingHours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> HourlyRate >> workingDays >> workingHours;
        if (employee == employee_name)
        {
            outfile.close();
            return HourlyRate;
        }
    }
    outfile.close();
    return 0;
}

int Employee::getWorkingDays(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string firstLine;
    getline (outfile,firstLine);
    std::string employee;
    double HourlyRate;
    int workingDays, workingHours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> HourlyRate >> workingDays >> workingHours;
        if (employee == employee_name)
        {
            outfile.close();
            return workingDays;
        }
    }
    outfile.close();
    return 0;
}

int Employee::getWorkingHours(std::string employee_name) const{
    std::ifstream outfile;
    outfile.open("working_plan.txt");
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string firstLine;
    getline (outfile,firstLine);
    std::string employee;
    double HourlyRate;
    int workingDays, workingHours;
    for (int i = 1; i <= 7; i ++)
    {
        outfile >> employee >> HourlyRate >> workingDays >> workingHours;
        if (employee == employee_name)
        {
            outfile.close();
            return workingHours;
        }
    }
    outfile.close();
    return 0;
}

void Employee::setName(std::string newFirstName, std::string newLastName) {
    firstName = newFirstName;
    lastName = newLastName;
}

void Employee::setEmailAdress(std::string newEmailAdress) {
    emailAdress = newEmailAdress;
}

void Employee::setPESEL(std::string newPESEL) {
    if (newPESEL.size() == 11)
        PESEL = newPESEL;
    else
        throw std::range_error("PESEL musi miec 11 cyfr");
}

void Employee::printRoster() {
    std::cout << "Roster for month: date and part of day \n";
    for(long unsigned int i = 0; i < roster.size(); i++){
        roster[i].first.get_day();
        std::cout << " " << roster[i].second << std::endl;
    }
}

void Employee::takeVacation(Date new_date){
    for(unsigned int i = 0; i < freeDays.size(); i++)
        if (new_date == freeDays[i].first)
            return;
    std::pair <Date, int> new_free_day;
    new_free_day.first = new_date;
    if (getWorkingDays(get_type()) > (30 - freeDays.size()))
        for (int i = 1; i <= 3; i++){
            new_free_day.second = i;
            freeDays.push_back(new_free_day);
        }
}

void Employee::removeVacation(Date date){
    std::pair <Date, int> free_day;
    free_day.first = date;
    for (int i = 1; i <= 3; i++){
        free_day.second = i;
        freeDays.erase(std::find(freeDays.begin(), freeDays.end(), free_day));
    }
}
