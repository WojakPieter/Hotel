#include "simulation.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

Simulation::Simulation(std::string file_name1, Date start_date1, std::string room_file1, std::string employee_file1)
{
    file_name = file_name1;
    start_date = start_date1;
    room_file_name = room_file1;
    employee_file_name = employee_file1;
}

void Simulation::start()
{
    set_hotel();
    std::ifstream outfile;
    outfile.open(file_name);
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    current_date = start_date;
    int relay = 1;

    std::string p = "";
    while (!outfile.eof())
    {
        outfile >> p;
        if (p == "CHANGE")
        {
            relay = change_relay(relay);
            hotel.change_current_employees(current_date, relay);
            outfile >> p;
        }

        // ile wartosci pobiera kazda metoda "p"
        // pobrac linie i z niej sprawdzic

        if (relay == 1 && start_date.get_day() == current_date.get_day())
        {
            hotel.creating_schedule(current_date);
            hotel.paying_the_bills();
            bool y = hotel.handing_out_salary();
        }

        /*if (p == "choose_entertainment")
        {
            std::string name, guest_pesel;
            outfile >> guest_pesel >> name;
            hotel.choose_entertainment(guest_pesel, name);
        }*/

        if (p == "add_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel >> hourlyRate;
            hotel.add_employee(type, firstN, lastN, email, pesel, hourlyRate);
        }

        if (p == "remove_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel >> hourlyRate;
            hotel.remove_employee(type, firstN, lastN, email, pesel, hourlyRate);
        }

        if (p == "check_in")
        {
            std::string first_name, last_name, email_adress, PESEL;
            double money;
            char type;
            bool high_standard, family;
            int first_date_day=1, first_date_month=1, first_date_year=1, last_date_day=2, last_date_month=1, last_date_year=1;
            outfile >> first_name >> last_name >> email_adress >> PESEL >> money;
            Guest guest(first_name, last_name, email_adress, PESEL, money);
            outfile >> type >> high_standard >> family;
            outfile >> first_date_day >> first_date_month >> first_date_year >> last_date_day >> last_date_month >> last_date_year;
            Date first_date(first_date_day, first_date_month, first_date_year);
            Date last_date(last_date_day, last_date_month, last_date_year);
            std::pair<Date, Date> period;
            period.first = first_date;
            period.second = last_date;
            hotel.check_in(guest, type, high_standard, family, period);
        }

        if (p == "remove_dish")
        {
            std::string type, name;
            outfile >> type >> name;
            hotel.remove_dish(type, name);
        }

        if (p == "add_dish")
        {
            std::string type, name, allergen, name_ingredient;
            double price, preparation_cost, preparation_time;
            int amount_of_allergens, amount_of_ingredients, mass;
            std::vector<Ingredient> ingredients;
            std::vector<std::string> allergens;
            outfile >> type >> name >> price >> preparation_cost >> preparation_time;
            outfile >> amount_of_allergens;
            for (int i = 1; i <= amount_of_allergens; i++)
            {
                outfile >> allergen;
                allergens.push_back(allergen);
            }
            outfile >> amount_of_ingredients;
            for (int i = 1; i <= amount_of_ingredients; i++)
            {
                outfile >> name_ingredient >> mass;
                Ingredient ingredient(name_ingredient, mass);
                ingredients.push_back(ingredient);
            }
            hotel.add_dish(type, name, price, preparation_cost, preparation_time, ingredients, allergens);
        }

        hotel.check_guests();
        // jezeli roznica miedzy datami %=7 to sprzatanie pokoi
        p = "";
    }
    outfile.close();
}

void Simulation::load_rooms()
{
    std::fstream room_file;
    room_file.open(room_file_name, std::ios::in);
    if(!room_file.good())
        throw std::logic_error("Couldn't open the file!");
    std::string line;
    while(std::getline(room_file, line))
    {
        std::stringstream line_str(line);
        int number;
        char type;
        bool is_high_standard, family;
        std::string nr_str, type_str, hs_str, f_str;
        getline(line_str, nr_str, ' ');
        number = std::atoi(nr_str.c_str());
        getline(line_str, type_str, ' ');
        type = type_str[0];
        getline(line_str, hs_str, ' ');
        getline(line_str, f_str, ' ');
        if(hs_str == "true")
            is_high_standard = true;
        if(hs_str == "false")
            is_high_standard = false;
        if(f_str == "true")
            family = true;
        if(f_str == "false")
            family = false;
        hotel.add_room(type, number, is_high_standard, family);
    }
    room_file.close();
}

void Simulation::load_employees()
{
    std::fstream employees_file;
    employees_file.open(employee_file_name, std::ios::in);
    if(!employees_file.good())
        throw std::logic_error("Couldn't open the file!");
    std::string line;
    while(std::getline(employees_file, line))
    {
        std::stringstream line_str(line);
        std::string first_name, last_name, email, pesel, type, rate_str;
        double rate;
        std::string::size_type sz;
        getline(line_str, first_name, ' ');
        getline(line_str, last_name, ' ');
        getline(line_str, email, ' ');
        getline(line_str, pesel, ' ');
        getline(line_str, type, ' ');
        getline(line_str, rate_str, ' ');
        rate = std::stod(rate_str);
        hotel.add_employee(type, first_name, last_name, email, pesel, rate);
    }
    employees_file.close();
}

void Simulation::set_hotel() {
    load_rooms();
    load_employees();

}

int Simulation::change_relay(int relay) {
    if (relay == 3) {
        current_date += 1;
        return 1;
    }
    else
        return relay+1;
}
