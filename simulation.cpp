#include "simulation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

Simulation::Simulation(std::string file_name1, Date start_date1, Hotel hotel1)
{
    file_name = file_name1;
    start_date = start_date1;
    hotel = hotel1;
}

void Simulation::start()
{
    // STALE:
    // sprawdzac zmiany employees - ustawianie atrybutow hotelu
    // sprawdzac czy nie trzeba kogos wymeldowac (HOTEL)
    
    std::ifstream outfile;
    outfile.open(file_name);
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    Date current_date = start_date;

    while (!outfile.eof())
    {
        if(start_date.get_day() == current_date.get_day())
        {
            hotel.creating_schedule(current_date);
            hotel.paying_the_bills();
        }
        hotel.check_
        // jezeli roznica miedzy datami %=7 to sprzatanie pokoi

        for (int relay = 1; relay <= 3; relay ++)
        {
            
        }

        current_date += 1;
    }

}