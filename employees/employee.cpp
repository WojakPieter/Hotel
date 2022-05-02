#include <iostream>
#include "employee.h"

std::string employee::getFirstName(){
    return firstName;
}

std::string employee::getLastName(){
    return lastName;
}

std::string employee::getEmailAdress(){
    return emailAdress;
}

std::string employee::getPESEL(){
    return PESEL;
}

double employee::getHourlyRate(){
    return hourlyRate;
}

void employee::setName(std::string newFirstName, std::string newLastName){
    firstName = newFirstName;
    lastName = newLastName;
}

void employee::setEmailAdress(std::string newEmailAdress){
    emailAdress = newEmailAdress;
}

void employee::setPESEL(std::string newPESEL){
    if (newPESEL.size() == 11)
        PESEL = newPESEL;
    else
        throw std::range_error("PESEL musi miec 11 cyfr");
}

void employee::setHourlyRate(double newRate){
    if (newRate > 0)
        hourlyRate = newRate;
    else
        throw std::range_error("Stawka godzinowa musi byc wieksza od zera");
}