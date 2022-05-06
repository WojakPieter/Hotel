#include <iostream>
#include "employee.h"
#include <algorithm>
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

    if (hourlyRate1 <= 0)
        hourlyRate = hourlyRate1;
    else
        throw std::range_error("Godzinowa stwka musi byc wieksza od zera");
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

double Employee::getHourlyRate() const{
    return hourlyRate;
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
    for(int i = 0; i < roster.size(); i++){
        roster[i].first.get_date();
        std::cout << " " << roster[i].second << std::endl;
    }
}
