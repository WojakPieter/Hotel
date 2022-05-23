#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include "hotel.h"
#include "date.cpp"

class Simulation
{
    std::string file_name;
    std::string room_file_name;
    std::string employee_file_name;
    Date start_date;
    Date current_date;
    Hotel hotel = Hotel("",0,0);

    public:
    Simulation(std::string, Date, std::string, std::string);
    void load_rooms();
    void load_employees();
    void start();
    int change_relay(int);
    void set_hotel();
    // pracownicy: dodanie, usuniecie, zmiana stawki
    // gosc: bookowanie, zmiana daty, wypisanie, rozrywki
};

#endif
