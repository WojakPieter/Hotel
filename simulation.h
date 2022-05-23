#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include "hotel.h"

class Simulation
{
    std::string file_name;
    std::string hotel_file;
    Date start_date;
    Date current_date;
    Hotel hotel = Hotel("",0,0);
    public:
    Simulation(std::string, Date, std::string);
    
    std::string get_file_name();
    void start();
    int change_relay(int);
    void set_hotel();
    void print_checking_in(std::string, std::string);
    void print_adding_employee(std::string, std::string);
    void print_removing_employee(std::string, std::string);
    void print_choosing_entertainment(std::string, std::string, std::string, int);
    void print_removing_dish(std::string);
    void print_adding_dish(std::string);
    void print_monthly_action(int, double, double);
    // pracownicy: dodanie, usuniecie, zmiana stawki
    // gosc: bookowanie, zmiana daty, wypisanie, rozrywki
};

#endif