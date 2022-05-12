#ifndef CPP_PROJECT_HOTEL_H
#define CPP_PROJECT_HOTEL_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "guest.h"
#include "data.h"
#include "data_room.h"
#include "menu.h"

class Hotel
{
    std::string name;
    int stars;
    double budget;
    std::vector <Guest> guests;
    Data employees; //(na tych bazach danych z pracy domowej)
    Data_room rooms;
    Menu menu;

    public:
    Hotel(std::string, int, double, std::vector<Guest>, Data, Data_room, Menu);

    void set_name(std::string new_name);
    void set_stars(int new_stars);
    void set_budget(double new_budget);
    void set_menu(Menu new_menu);
    // + settery

    void check_in(); //gosc i losowanie mu pokoju
    void check_out(Guest);
    void shortening_the_stay(Guest, Date);
    void handing_out_salary();
    void creating_schedule(); //odwolanie u kazdego pracownika do funkcji make_roster
    void paying_the_bills();
}