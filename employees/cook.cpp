#include <iostream>
#include "recepcionist.h"
#include "employee.h"
#include "Date.h"
#include "cook.h"

cook::cook(std::string firstName1, std::string lastName1, std::string emailAdress1, std::string PESEL1, double hourlyRate1, std::vector<std::pair<Date, int>> roster1, std::vector<Date> freeDays1)
{
    firstName = firstName1;
    lastName = lastName1;
    emailAdress = emailAdress1;
    PESEL = PESEL1;
    hourlyRate = hourlyRate1;
    roster = roster1;
    freeDays = freeDays1;
}

double cook::workingHours()
{
    return 8*roster.size();
}

double cook::salary()
{
    return hourlyRate*workingHours();
}