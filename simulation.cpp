#include <math.h>
#include "simulation.h"
// #include <windows.h>
#include <iostream>
#include <random>
#include <string>
// #include <conio.h>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>

Simulation::Simulation(int days1, Date start_date1, std::string room_file1, std::string employee_file1, std::string simulation_file1, std::string menu_file_name1, std::string guest_file_name1)
{
    days = days1;
    start_date = start_date1;
    room_file_name = room_file1;
    employee_file_name = employee_file1;
    simulation_file = simulation_file1;
    menu_file_name = menu_file_name1;
    guest_file_name = guest_file_name1;
}

std::vector<Guest> Simulation::get_guests_to_add()
{
    return guests_to_add;
}

std::vector<Guest> Simulation::get_current_guests()
{
    return current_guests;
}

void Simulation::start()
{
    set_hotel();

    clear_simulation_file();

    int i = 0;
    current_date = start_date;
    int relay = 1;
    while(current_date < start_date + days) {
        std::default_random_engine generator;
        generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> distribution(0,activity.size()-1);
        int chosen_activity_index = distribution(generator);
        std::string p = activity[chosen_activity_index];
    if (i == 0 && relay == 1 && start_date.get_day() == current_date.get_day())
        {
            int nr_of_employees = hotel.creating_schedule(current_date);
            double bills = hotel.paying_the_bills();
            double cash = hotel.handing_out_salary();
            i = 1;
            print_monthly_action(nr_of_employees, cash, bills);
            // Sleep(1000);
        }
        if (p == "CHANGE")
        {
            relay = change_relay(relay);
            hotel.change_current_employees(current_date, relay);
            print_current_employees();
            if(relay == 1) hotel.check_guests();
        }



        else if (p == "choose_entertainment")
        {

            if(current_guests.size() == 0) continue;
            drawing_the_choosing_entertainment();
        }
        else if (p == "book_room")
            drawing_the_booking_room();

        else if (p == "change_stay")
        {
            if(current_guests.size() == 0) continue;
            drawing_the_changing_stay();
        }
        else
            print_wrong_activity(p);


        // Sleep(1000);
        p = "";
    }
}


void Simulation::drawing_the_changing_stay()
{
    std::default_random_engine generator;
    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::vector<Guest> guests = hotel.get_guests();
    std::uniform_int_distribution<int> distribution(0,current_guests.size()-1);
    int chosen_guest_index = distribution(generator);
    Guest chosen_guest = current_guests[chosen_guest_index];

    int minimum_days = current_date - chosen_guest.get_last_date() + 1;
    std::uniform_int_distribution<int> distribution2(minimum_days,30);
    int days = distribution2(generator);
    Date new_stay_date = current_date + days;

    bool flag = hotel.shortening_the_stay(chosen_guest, new_stay_date);
}


void Simulation::drawing_the_choosing_entertainment()
{
    std::default_random_engine generator;
    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0,entertainment.size()-1);
    int chosen_entertainment_index = distribution(generator);
    std::string name = activity[chosen_entertainment_index];

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::vector<Guest> guests = hotel.get_guests();
    std::uniform_int_distribution<int> distribution2(0,guests.size()-1);
    int chosen_guest_index = distribution2(generator);
    Guest chosen_guest = guests[chosen_guest_index];

    std::string dish_type;
    int hour;
    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());

    if (name == "order_dish") {
        std::vector<Dish> menu = hotel.get_menu();
        std::uniform_int_distribution<int> distribution3(0,menu.size()-1);
        int chosen_dish_index = distribution3(generator);
        dish_type = menu[chosen_dish_index].get_name();
    }

    if (name == "order_waking_up")
    {
        std::uniform_int_distribution<int> distribution4(0,23);
        hour = distribution4(generator);
    }

    std::string flag = hotel.choose_entertainment(chosen_guest.get_PESEL(), name, dish_type, hour);
    print_choosing_entertainment(chosen_guest.get_PESEL(), name, dish_type, hour, flag);
}


void Simulation::drawing_the_booking_room()
{
    std::default_random_engine generator;
    unsigned seed1 = std::chrono::steady_clock::now().time_since_epoch().count();
    generator.seed(seed1);
    std::vector<char> types_of_room = {'1', '2', '3', '4', 'a', 's'};
    std::uniform_int_distribution<int> distribution(0,types_of_room.size()-1);
    int chosen_type_index = distribution(generator);
    char type = types_of_room[chosen_type_index];

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::vector<bool> true_or_false = {true, false};
    std::uniform_int_distribution<int> distribution2(0,true_or_false.size()-1);
    int chosen_index = distribution2(generator);
    bool high_standard = true_or_false[chosen_index];

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution3(0,true_or_false.size()-1);
    int chosen_index3 = distribution3(generator);
    bool family = true_or_false[chosen_index3];

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution4(0,365);
    int days_to_book = distribution4(generator);

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution5(1,30);
    int length_of_stay = distribution5(generator);

    Date first_date = current_date + days_to_book;
    Date last_date = first_date + length_of_stay;

    std::pair<Date, Date> period;
    period.first = first_date;
    period.second = last_date;

    generator.seed(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution6(0,guests_to_add.size()-1);
    int chosen_guest_index = distribution6(generator);
    Guest guest = guests_to_add[chosen_guest_index];

    int room_number = hotel.book_room(guest, type, high_standard, family, period);
    print_checking_in(guest.get_first_name(), guest.get_last_name(), room_number);
    if(room_number != -1) current_guests.push_back(guest);
}


void Simulation::print_current_employees()
{
    std::string text = "CHANGE! Employees on change: \n";
    text += hotel.print_current_employees();
    write_to_file(text);
    std::cout << text << std::endl;
}

void Simulation::print_changing_stay(std::string guest_pesel, Date new_date, bool flag)
{
    std::string text = "Guest with PESEL " + guest_pesel + " change the stay in hotel to " + new_date.print();
    if(!flag)
        text = "Impossible attempt to change stay for guest with PESEL " + guest_pesel;
    write_to_file(text);
    std::cout << text << std::endl;
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
        days --;
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
        line_str >> first_name >> last_name >> email >> pesel >> type >> rate;
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
        std::string type, name, ingredient_name;
        double price, preparation_cost, preparation_time;
        int ingredient_quantity;
        line_str >> type >> name >> price >> preparation_cost >> preparation_time;
        std::vector<Ingredient> ingredients;
        while(!line_str.eof())
        {
                line_str >> ingredient_name >> ingredient_quantity;
                Ingredient i(ingredient_name, ingredient_quantity);
                ingredients.push_back(i);
        }
        hotel.add_dish(type, name, price, preparation_cost, preparation_time, ingredients, {});
    }
}

void Simulation::load_guests()
{
    std::fstream guest_file;
    guest_file.open(guest_file_name, std::ios::in);
    if(!guest_file.good())
        throw std::logic_error("Could not open guest file");
    std::string line;
    while(getline(guest_file, line))
    {
        std::stringstream line_str(line);
        std::string name, last_name, email, PESEL;
        double budget;
        line_str >> name >> last_name >> email >> PESEL >> budget;
        Guest g(name, last_name, email, PESEL, budget);
        guests_to_add.push_back(g);
    }

}

void Simulation::set_hotel() {
    load_rooms();
    load_employees();
    load_guests();
    load_menu();

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

