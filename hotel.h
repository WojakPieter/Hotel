#ifndef CPP_PROJECT_HOTEL_H
#define CPP_PROJECT_HOTEL_H
#include <iostream>
#include <string>
#include <vector>
#include "guest.h"
#include "employees/data.h"
#include "database.h"
#include "menu.h"

class Hotel
{
    std::string name;
    int stars;
    double budget;
    std::vector <Guest> guests;
    Data employees; //(na tych bazach danych z pracy domowej)
    Data_room rooms;
    Menu menu = Menu("",{},{});
    Date current_date;
    Data current_employees;

    public:
    Hotel(std::string, int, double);

    std::string get_name();
    int get_stars();
    double get_budget();
    Date get_current_date();

    void add_employee(std::string, std::string, std::string, std::string, std::string, double);
    void remove_employee(std::string, std::string, std::string, std::string, std::string, double);
    void change_employee_rate(std::string, double);

    // DO ZROBIENIA 4 FUNKCJE:
    void add_room();
    void remove_room();
    void change_room_price();
    void set_current_employees();
    void change_current_employees(Date, int);
    void choose_entertainment(std::string guest_pesel, std::string name);
    void check_guests();

    void add_dish(std::string, std::string, double, double, double, std::vector<Ingredient>, std::vector<std::string>);
    void remove_dish(std::string, std::string);

    void set_name(std::string new_name);
    void set_stars(int new_stars);
    void set_budget(double new_budget);
    void increment_current_date();
    void increase_budget(double income);
    bool decrease_budget(double outgo);
    bool check_in(Guest guest, char type, bool high_standard, bool family, std::pair<Date, Date> period); //gosc i losowanie mu pokoju
    void check_out(Guest&);
    bool shortening_the_stay(Guest&, Date);
    bool handing_out_salary();
    void creating_schedule(Date); //odwolanie u kazdego pracownika do funkcji make_roster
    void paying_the_bills();
};
#endif
