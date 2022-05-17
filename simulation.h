#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include "hotel.h

class Simulation
{
    std::string file_name;
    Date start_date;
    Hotel hotel;

    public:
    Simulation(std::string, Date, Hotel);
    
    void start();

}

#endif