#include <math.h>
#include "simulation.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

Simulation::Simulation(std::string file_name1, Date start_date1, std::string room_file1, std::string employee_file1, std::string simulation_file1, std::string menu_file_name1)
{
    file_name = file_name1;
    start_date = start_date1;
    room_file_name = room_file1;
    employee_file_name = employee_file1;
    simulation_file = simulation_file1;
    menu_file_name = menu_file_name1;
}

std::string Simulation::get_file_name() {
    return file_name;
}

void Simulation::start()
{
    set_hotel();

    clear_simulation_file();

    std::ifstream outfile;
    outfile.open(file_name);
    if (!outfile) {
        throw std::logic_error("Couldn't open the file with activity in simulation!");
    }
    std::string p="";
    int i = 0;
    current_date = start_date;
    int relay = 1;
    while (!outfile.eof())
    {
        outfile >> p;
        if (p == "CHANGE")
        {
            relay = change_relay(relay);
            hotel.change_current_employees(current_date, relay);
            i = 0;
            outfile >> p;
        }


        if (i == 0 && relay == 1 && start_date.get_day() == current_date.get_day())
        {
            int nr_of_employees = hotel.creating_schedule(current_date);
            double bills = hotel.paying_the_bills();
            double cash = hotel.handing_out_salary();
            i = 1;
            print_monthly_action(nr_of_employees, cash, bills);
            Sleep(1000);
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
            std::string flag = hotel.choose_entertainment(guest_pesel, name, type, hour);
            print_choosing_entertainment(guest_pesel, name, type, hour, flag);
        }

        else if (p == "add_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel;
            outfile >> hourlyRate;
            bool flag = hotel.add_employee(type, firstN, lastN, email, pesel, hourlyRate);
            print_adding_employee(firstN, lastN, flag);
        }

        else if (p == "remove_employee")
        {
            std::string type, firstN, lastN, email, pesel;
            double hourlyRate;
            outfile >> type >> firstN >> lastN >> email >> pesel >> hourlyRate;
            bool flag = hotel.remove_employee(type, firstN, lastN, email, pesel, hourlyRate);
            print_removing_employee(firstN, lastN, flag);
        }

        else if (p == "book_room")
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
            int room_number = hotel.book_room(guest, type, high_standard, family, period);
            print_checking_in(first_name, last_name, room_number);
        }

        else if (p == "remove_dish")
        {
            std::string type, name;
            outfile >> type >> name;
            bool flag = hotel.remove_dish(type, name);
            print_removing_dish(name, flag);
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
            bool flag = hotel.add_dish(type, name, price, preparation_cost, preparation_time, ingredients, allergens);
            print_adding_dish(name, flag);
        }
        else
        {
            print_wrong_activity(p);
        }
        hotel.check_guests();
        Sleep(1000);
        p = "";
    }
    outfile.close();
}

void Simulation::print_wrong_activity(std::string activity)
{
    std::string text = "Activity named " + activity + " does not exist";
    write_to_file(text);
    std::cout << text << std::endl;
}


void Simulation::print_adding_employee(std::string first_name, std::string last_name, bool flag) {
    std::string text = first_name + " " + last_name + " was just hired";
    if(!flag)
        text = "Impossible attempt to add a employee named " + first_name + " " + last_name;
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_monthly_action(int nr_of_employees, double cash, double bills){
    std::string text = "Hotel created a schedule for " + std::to_string(nr_of_employees) + " employees\n";
    text += "Hotel paid " + std::to_string(int(bills)) + "." + std::to_string(int(bills*100) % 100) + " zl for the bills\n";
    text += "Hotel paid " + std::to_string(int(cash)) + "." + std::to_string(int(cash*100) % 100) + " zl for the employees' salaries";
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_removing_employee(std::string first_name, std::string last_name, bool flag) {
    std::string text = first_name + " " + last_name + " was just fired";
    if(!flag)
        text = "Impossible attempt to remove a notexistent employee named " + first_name + " " + last_name;
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_checking_in(std::string first_name, std::string last_name, int room_number) {
    std::string text = first_name + " " + last_name + " booked the room nr " + std::to_string(room_number);
    if (room_number == -1)
        text = "It is not possible to book a room for " + first_name + " " + last_name;
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_choosing_entertainment(std::string PESEL, std::string name, std::string type, int nr, std::string flag) {
    int room_number = 0;
    for(Guest guest : hotel.get_guests())
    {
        if(guest.get_PESEL() == PESEL) room_number = guest.get_room_number();
    }
    std::string text = "Guest with PESEL " + PESEL + " " + name;
    if(name == "order_tidying_room")
        text = "Room nr " + std::to_string(room_number) + " has been tidied by " + flag;
    if (name == "order_waking_up")
        text += "at " + std::to_string(nr);
    if (flag == "false")
        text = "Guest with PESEL " + PESEL + " cannot choose this entertainment";
    if (name == "order_dish")
    {
        if(flag != "false")
            text += ": " + type;
        else
        {
            text = "Guest with PESEL " + PESEL + " tried to order non-existing dish";
        }
    }
    write_to_file(text);
    std::cout << text << std::endl;
    if(name == "order_tidying_room")
        std::cout << "Room nr " << nr << " has been tidied by " << flag << std::endl;
}

void Simulation::print_removing_dish(std::string name, bool flag) {
    std::string text = name + " was removed from menu";
    if (!flag)
        text = "Impossible attempt to remove a notexistent dish named " + name;
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_adding_dish(std::string name, bool flag) {
    std::string text = name + " was added to menu";
    if (!flag)
        text = "Impossible attempt to add a dish named " + name;
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_tidying_room(Guest guest, std::string PESEL)
{
    std::cout << "Room nr " << guest.get_room_number() << " has been tidied by " << PESEL << std::endl;
}

int Simulation::change_relay(int relay) {
    if (relay == 3) {
        current_date += 1;
        return 1;
    }
    else
        return relay+1;
}

void Simulation::load_rooms()
{
    std::fstream room_file;
    room_file.open(room_file_name, std::ios::in);
    if(!room_file.good())
        throw std::logic_error("Couldn't open the file with hotel's rooms!");
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
        throw std::logic_error("Couldn't open the file with hotel's employees!");
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

void Simulation::load_menu()
{
    std::fstream menu_file;
    menu_file.open(menu_file_name, std::ios::in);
    if(!menu_file.good())
        throw std::logic_error("Could not open menu file!");
    std::string line;
    while(std::getline(menu_file, line))
    {
        std::stringstream line_str(line);
        std::string type, name, price_str, preparation_cost_str, preparation_time_str, ingredient_name, ingredient_quantity;
        getline(line_str, type, ' ');
        getline(line_str, name, ' ');
        getline(line_str, price_str, ' ');
        std::vector<Ingredient> ingredients;
        while(!line_str.eof())
        {
            try
            {
                getline(line_str, ingredient_name, ' ');
                getline(line_str, ingredient_quantity, ' ');
                Ingredient i(ingredient_name, std::stod(ingredient_quantity));
                ingredients.push_back(i);
            }
            catch (...)
            {
                break;
            }
        }
        Dish d(name,std::stod(price_str), std::stod(preparation_cost_str), std::stod(preparation_time_str), ingredients);
        hotel.add_dish(type, name, std::stod(price_str), std::stod(preparation_cost_str), std::stod(preparation_time_str), ingredients, {});
    }
}

void Simulation::set_hotel() {
    load_rooms();
    load_employees();

}

void Simulation::write_to_file(std::string text) {
    std::ofstream file;
    file.open(simulation_file, std::ios::app);
    if (!file) {
        throw std::logic_error("Couldn't open the file to write a simulation!");
    }
    file << text << std::endl;
    file.close();
}

void Simulation::clear_simulation_file() {
    std::ofstream file;
    file.open(simulation_file);
    if (!file) {
        throw std::logic_error("Couldn't open the file with simulation!");
    }
    file.close();
}

