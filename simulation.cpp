#include "simulation.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

Simulation::Simulation(std::string file_name1, Date start_date1, std::string hotel_file1)
{
    file_name = file_name1;
    start_date = start_date1;
    hotel_file = hotel_file1;
}

std::string Simulation::get_file_name() {
    return file_name;
}

void Simulation::start()
{
    // set_hotel();

    std::ifstream outfile;
    outfile.open(file_name);
    if (!outfile) {
        throw std::logic_error("Couldn't open the file!");
    }
    std::string p="";
    current_date = start_date;
    int relay = 1;   
    while (!outfile.eof())
    {
        outfile >> p;
        if (p == "CHANGE")
        {
            relay = change_relay(relay);
            hotel.change_current_employees(current_date, relay);
            outfile >> p;
        }


        if (relay == 1 && start_date.get_day() == current_date.get_day())
        {
            int nr_of_employees = hotel.creating_schedule(current_date);
            double bills = hotel.paying_the_bills();
            double cash = hotel.handing_out_salary();

            print_monthly_action(nr_of_employees, cash, bills);
        }

        if (p == "choose_entertainment")
        {
            std::string name, guest_pesel, type;
            int hour;
            outfile >> guest_pesel >> name;
            if (name == "order_dish")
                outfile >> type;
            if (name == "order_waking_up")
                outfile >> hour;
            hotel.choose_entertainment(guest_pesel, name, type, hour);
            print_choosing_entertainment(guest_pesel, name, type, hour);
        }

        else if (p == "add_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel;
            outfile >> hourlyRate;
            hotel.add_employee(type, firstN, lastN, email, pesel, hourlyRate);
            print_adding_employee(firstN, lastN);
        }

        else if (p == "remove_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel >> hourlyRate;
            hotel.remove_employee(type, firstN, lastN, email, pesel, hourlyRate);
            print_removing_employee(firstN, lastN);
        }

        else if (p == "check_in") 
        {
            std::string first_name, last_name, email_adress, PESEL;
            double money;
            char type;
            bool high_standard, family;
            int first_date_day, first_date_month, first_date_year, last_date_day, last_date_month, last_date_year;
            outfile >> first_name >> last_name >> email_adress >> PESEL;
            outfile >> money;
            Guest guest(first_name, last_name, email_adress, PESEL, money);
            outfile >> type;
            outfile >> high_standard >> family;
            outfile >> first_date_day >> first_date_month >> first_date_year >> last_date_day >> last_date_month >> last_date_year;
            Date first_date(first_date_day, first_date_month, first_date_year);
            Date last_date(last_date_day, last_date_month, last_date_year);
            std::pair<Date, Date> period;
            period.first = first_date;
            period.second = last_date;
            hotel.check_in(guest, type, high_standard, family, period);
            print_checking_in(first_name, last_name);
        }

        else if (p == "remove_dish") 
        {
            std::string type, name;
            outfile >> type >> name;
            hotel.remove_dish(type, name);
            print_removing_dish(name);
        }

        else if (p == "add_dish")
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
            print_adding_dish(name);
        }

        hotel.check_guests();
        p = "";
    }
    outfile.close();
}

void Simulation::set_hotel() {
    std::ifstream outfile;
    outfile.open(hotel_file);
    if (!outfile) {
        throw std::logic_error("Couldn't open the file with basic hotel!");
    }
    while (!outfile.eof()){}
}

void Simulation::print_adding_employee(std::string first_name, std::string last_name) {
    std::cout << first_name << " " << last_name;
    std::cout << " was just hired" << std::endl;
}

void Simulation::print_monthly_action(int nr_of_employees, double cash, double bills){
    std::cout << "Hotel created a schedule for " << nr_of_employees << " employees." << std::endl;
    std::cout << "Hotel paid " << bills << " zl for the bills." << std::endl;
    std::cout << "Hotel paid " << cash << " zl for the employees' salaries." << std::endl;
}

void Simulation::print_removing_employee(std::string first_name, std::string last_name) {
    std::cout << first_name << " " << last_name;
    std::cout << " was just fired" << std::endl;
}

void Simulation::print_checking_in(std::string first_name, std::string last_name) {
    std::cout << first_name << " " << last_name;
    std::cout << " booked the room." << std::endl;
}

void Simulation::print_choosing_entertainment(std::string PESEL, std::string name, std::string type, int nr) {
    std::cout << "Guest with PESEL " << PESEL << " " << name;
    if (name == "order_dish")
        std::cout << ": " << type << std::endl;
    if (name == "order_waking_up")
        std::cout << "at " << nr << std::endl;
}

void Simulation::print_removing_dish(std::string name) {
    std::cout << name << " was removed from menu" << std::endl;
}

void Simulation::print_adding_dish(std::string name) {
    std::cout << name << " was added to menu" << std::endl;
}

int Simulation::change_relay(int relay) {
    if (relay == 3) {
        current_date += 1;
        return 1;
    }
    else
        return relay+1;
}