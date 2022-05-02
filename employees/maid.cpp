#include <iostream>
#include "recepcionist.h"
#include "employee.h"
#include "Date.h"
#include "maid.h"

maid::maid(std::string firstName1, std::string lastName1, std::string emailAdress1, std::string PESEL1, double hourlyRate1, std::vector<std::pair<Date, int>> roster1, std::vector<Date> freeDays1)
{
    firstName = firstName1;
    lastName = lastName1;
    emailAdress = emailAdress1;
    PESEL = PESEL1;
    hourlyRate = hourlyRate1;
    roster = roster1;
    freeDays = freeDays1;
}

double maid::workingHours()
{
    return 8*roster.size();
}

double maid::salary()
{
    return hourlyRate*workingHours();
}