#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include "hotel.h

class Simulation
{
    std::string file_name;
    std::string hotel_file;
    Date start_date;
    Date current_date;
    Hotel hotel;

    public:
    Simulation(std::string, Date);
    
    void start();
    int change_relay(int);
    void set_hotel();
    // pracownicy: dodanie, usuniecie, zmiana stawki
    // gosc: bookowanie, zmiana daty, wypisanie, rozrywki
}

#endif