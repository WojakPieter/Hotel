#include <iostream>
#include <string>
#include <vector>
#include "maid.h"

maid::maid(std::string firstName, std::string lastName, std::string emailAdress, std::string PESEL, double hourlyRate):
employee(firstName, lastName, emailAdress, PESEL, hourlyRate)
{}

double maid::workingHours()
{
    int days = roster.size();
    return 9*days;
}

double maid::salary()
{
    return hourlyRate*workingHours();
}

void maid::setHourlyRate(double newRate) {
    if (newRate > 0)
        hourlyRate = newRate;
    else
        throw std::range_error("Stawka godzinowa musi byc wieksza od zera");
}