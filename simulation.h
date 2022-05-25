#ifndef CPP_PROJECT_SIMULATION_H
#define CPP_PROJECT_SIMULATION_H
#include <iostream>
#include <string>
#include <vector>
#include "hotel.h"

class Simulation
{
    std::string file_name;
    std::string room_file_name;
    std::string employee_file_name;
    std::string simulation_file;
    Date start_date;
    Date current_date;
    Hotel hotel = Hotel("",0,0);

    public:
    Simulation(std::string, Date, std::string, std::string, std::string);
    
    std::string get_file_name();
    void start();
    int change_relay(int);
    void load_rooms();
    void load_employees();
    void set_hotel();

    void clear_simulation_file();
    void write_to_file(std::string);

// gettery i settery
    // void print_change_date_of_stay();  dorobic

    void print_checking_in(std::string, std::string, int);
    void print_adding_employee(std::string, std::string);
    void print_removing_employee(std::string, std::string);
    void print_choosing_entertainment(std::string, std::string, std::string, int);
    void print_removing_dish(std::string);
    void print_adding_dish(std::string);
    void print_monthly_action(int, double, double);
};

#endif