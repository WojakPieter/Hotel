
#include "hotel.h"
#include <string>
#include <iostream>
#include <random>

Hotel::Hotel(std::string name1, int stars1, double budget1)
{
    name = name1;
    stars = stars1;
    budget = budget1;
}

std::string Hotel::get_name()
{
    return name;
}

int Hotel::get_stars()
{
    return stars;
}

double Hotel::get_budget()
{
    return budget;
}

Date Hotel::get_current_date()
{
    return current_date;
}

std::vector<Guest> Hotel::get_guests()
{
    return guests;
}

std::vector<Dish> Hotel::get_menu()
{
    std::vector<Dish> things;
    for(Dish d : menu.get_food())
    {
        things.push_back(d);
    }
    for(Dish d : menu.get_drinks())
    {
        things.push_back(d);
    }
}

void Hotel::increment_current_date()
{
    current_date++;
}

void Hotel::increase_budget(double income)
{
    budget += income;
}

bool Hotel::decrease_budget(double outgo)
{
    if(budget - outgo >=0)
    {
        budget -= outgo;
        return true;
    }
    return false;
}

bool Hotel::add_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {
    bool flag = employees.add_employee(type,first_name,second_name,email_adress,pesel,hourly_rate);
    return flag;
}

bool Hotel::remove_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {
    bool flag = employees.remove_employee(type,first_name,second_name,email_adress,pesel,hourly_rate);
    return flag;
}

void Hotel::change_employee_rate(std::string pesel, double new_rate){
    employees.set_employee_rate(pesel, new_rate);
}

std::string Hotel::set_maid_to_tidy_room(int number)
{
    int i=0;
    bool flag=false;
    std::vector<int> index_of_maids = {};
    for(auto& ptr : current_employees)
    {
        if(ptr->get_type() == "maid")
        {
        index_of_maids.push_back(i);
        i++;
        flag = true;
        }
    }
    if(flag)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,index_of_maids.size()-1);
        int chosen_maid_index = distribution(generator);
        int i = 0;
        for(auto& ptr : current_employees)
        {
            if(i == index_of_maids[chosen_maid_index]) std::cout << ptr -> get_type();
            i++;
        }
        current_employees[index_of_maids[chosen_maid_index]] -> tidy_room();
        return current_employees[index_of_maids[chosen_maid_index]] -> get_PESEL();
    }
    else return "none";
}

int Hotel::book_room(Guest guest, char type, bool high_standard, bool family, std::pair<Date, Date> period)
{
    std::vector<int> numbers_of_matching_rooms;
    bool flag = false;
    for(auto& ptr : rooms)
    {
        if(ptr->get_type() == type && ptr->is_high_standard() == high_standard && ptr->is_family() == family && !ptr->is_reserved_in_period(period))
        {
            if(guest.get_money() >= (ptr->get_price()*(period.second-period.first+1))) {
                numbers_of_matching_rooms.push_back(ptr->get_number());
                guest.set_receipt(ptr->get_price()*(period.second-period.first+1) + guest.get_receipt());
                flag = true;
            }
        }
    }
    if(flag)
    {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,numbers_of_matching_rooms.size()-1);
        int chosen_room_index = distribution(generator);
        int room_number = numbers_of_matching_rooms[chosen_room_index];
        rooms.book_room(room_number, period);
        guest.set_room_number(room_number);
        guest.set_first_date(period.first);
        guest.set_last_date(period.second);
        guests.push_back(guest);
        return room_number;
    }
    return -1;
}

void Hotel::check_in(Guest guest)
{

    guest.subtract_money(guest.get_receipt());
    increase_budget(guest.get_receipt());
}


bool Hotel::add_dish(std::string type, std::string name, double price, double prep_cost, double prep_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens)
{
    bool flag = false;
    Dish dish(name, price, prep_cost, prep_time, ingredients, allergens);
    if (type == "drink")
        flag = menu.add_drink(dish);
    else
        flag = menu.add_food(dish);
    return flag;
}

bool Hotel::remove_dish(std::string type, std::string name)
{
    bool flag = false;
    if(type == "drink")
        flag = menu.remove_drink(name);
    else
        flag = menu.remove_food(name);
    return flag;
}

void Hotel::add_room(char type, int number, bool is_high_standard, bool is_family)
{
    switch(type)
    {
        case '1':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<OnePersonRoom>(number, is_high_standard);
                rooms.add_room(std::move(room_ptr));
                break;
            }
        case '2':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<TwoPersonRoom>(number, is_high_standard, is_family);
                rooms.add_room(std::move(room_ptr));
                break;
            }
        case '3':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<ThreePersonRoom>(number, is_high_standard, is_family);
                rooms.add_room(std::move(room_ptr));
                break;
            }
        case '4':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<FourPersonRoom>(number, is_high_standard, is_family);
                rooms.add_room(std::move(room_ptr));
                break;
            }
        case 's':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<Studio>(number);
                rooms.add_room(std::move(room_ptr));
                break;
            }
        case 'a':
            {
                std::unique_ptr<Room> room_ptr = std::make_unique<Apartment>(number);
                rooms.add_room(std::move(room_ptr));
                break;
            }
    }
}

void Hotel::remove_room(int number)
{
    for(auto& ptr : rooms)
    {
        if(ptr->get_number() == number)
        {
            rooms.remove_room(std::move(ptr));
        }
    }
}

void Hotel::check_out(Guest& guest)
{
    for(unsigned int i = 0; i < guests.size(); i++)
        if (guest.get_PESEL() == guests[i].get_PESEL())
        {
            guests.erase(guests.begin() + i);
            break;
        }
    increase_budget(guest.get_receipt());
    // zamowic sprzatanie u sprzataczki
}

void Hotel::check_guests()
{
    for(Guest& g : guests)
    {
        if(g.get_first_date() == current_date) check_in(g);
        if(g.get_last_date() == current_date) check_out(g);
    }
}

void Hotel::change_current_employees(Date date, int change)
{
    current_employees.clear();
    for(auto& ptr : employees)
    {
        if(ptr->works_in_a_change(date,change))
            current_employees.add_employee(ptr->get_type(),ptr->get_first_name(),ptr->get_last_name(), ptr->get_email_adress(), ptr->get_PESEL(), ptr->get_hourly_rate(ptr->get_type()));
    }
}

double Hotel::handing_out_salary()
{
    double outgo = 0;
    for(auto& ptr : employees)
    {
        outgo += ptr->salary();
    }
    bool flag = decrease_budget(outgo);
    return outgo;
}

int Hotel::creating_schedule(Date date)
{
    int nr_of_employees = 0;
    std::vector<std::pair<Date, int>> changes;
    for(int i=0; i<current_date.get_month_length(current_date.get_month()); i++)
    {
        changes.push_back(std::make_pair<Date, int>(date+i,1));
        changes.push_back(std::make_pair<Date, int>(date+i,2));
        changes.push_back(std::make_pair<Date, int>(date+i,3));
    }
    for(auto& ptr : employees)
    {
        ptr->make_roster(changes);
        nr_of_employees += 1;
    }
    return nr_of_employees;
}

bool Hotel::shortening_the_stay(Guest& guest, Date new_last_date)
{
    for(auto& room_ptr : rooms)
    {
        if(room_ptr->get_number() == guest.get_room_number())
        {
            double receipt = 0;
            if (guest.last_day >= new_last_date) {
                double days = new_last_date - guest.last_day;
                receipt = receipt - days*room_ptr->get_price();
                while(guest.last_day > new_last_date)
                {
                    room_ptr->remove_reserved_day(new_last_date);
                    new_last_date++;
                }
            }
            else {
                double days = guest.last_day - new_last_date;
                if(days*room_ptr->get_price()+receipt >= guest.get_money())
                {
                    Date current_checked_date;
                    receipt += days*room_ptr->get_price();
                    while(guest.last_day < new_last_date)
                    {
                        current_checked_date = guest.last_day + 1;
                        if(room_ptr->is_reserved_at_day(current_checked_date)) return false;
                    }
                    while(guest.last_day <= new_last_date)
                    {
                        room_ptr->add_reserved_day(guest.last_day);
                        guest.last_day++;
                    }
                    decrease_budget(receipt);
                    return true;
                }
                else return false;
            }
        }
    }
    return false;
}

double Hotel::paying_the_bills()
{
    double bill = 0;
    for(auto& room_ptr : rooms)
    {
        std::pair<double,double> func = room_ptr->get_maintain_costs_function();
        bill += (func.first * room_ptr->quantity_of_reserved_days(current_date - current_date.get_month_length(current_date.get_month()), current_date) + func.second);
    }
    return bill;
}

std::string Hotel::choose_entertainment(std::string PESEL, std::string name, std::string type, int hour) {
    for(Guest& g : guests)
    {
        if(g.get_PESEL() == PESEL)
        {

            if(name == "order_taxi") {
                bool flag = g.order_taxi();
                if(flag) return "true";
                else return "false";
            }

            else if(name == "order_waking_up") {
                bool flag = g.order_waking_up(hour);
                if(flag) return "true";
                else return "false";
            }

            else if(name == "order_tidying_room") {
                bool flag = g.order_tidying_room();
                if(flag)  return set_maid_to_tidy_room(g.get_room_number());
                else return "false";
            }

            else if(name == "order_dish") {
                bool flag = g.order_dish(type, menu);
                if(flag) return "true";
                else return "false";
            }
            else
                return "false";
        }
    }
    return "false";
}
