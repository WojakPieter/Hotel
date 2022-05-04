#include <iostream>
#include "employee.h"

employee::employee(std::string firstName1, std::string lastName1, std::string emailAdress1, std::string PESEL1, double hourlyRate1)
{
    firstName = firstName1;
    lastName = lastName1;
    emailAdress = emailAdress1;
    PESEL = PESEL1;
    hourlyRate = hourlyRate1;
}

std::string employee::getFirstName() const{
    return firstName;
}

std::string employee::getLastName() const{
    return lastName;
}

std::string employee::getEmailAdress() const{
    return emailAdress;
}

std::string employee::getPESEL() const{
    return PESEL;
}

double employee::getHourlyRate() const{
    return hourlyRate;
}

void employee::setName(std::string newFirstName, std::string newLastName) {
    firstName = newFirstName;
    lastName = newLastName;
}

void employee::setEmailAdress(std::string newEmailAdress) {
    emailAdress = newEmailAdress;
}

void employee::setPESEL(std::string newPESEL) {
    if (newPESEL.size() == 11)
        PESEL = newPESEL;
    else
        throw std::range_error("PESEL musi miec 11 cyfr");
}
