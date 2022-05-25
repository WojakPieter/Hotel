#include "hotel.h"
#include <string>
#include <iostream>

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

void Hotel::add_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {
    employees.add_employee(type,first_name,second_name,email_adress,pesel,hourly_rate);
}

void Hotel::remove_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {
    employees.remove_employee(type,first_name,second_name,email_adress,pesel,hourly_rate);
}

void Hotel::change_employee_rate(std::string pesel, double new_rate){
    employees.set_employee_rate(pesel, new_rate);
}

int Hotel::check_in(Guest guest, char type, bool high_standard, bool family, std::pair<Date,Date> period)
{
    for(auto& ptr : rooms)
    {
        if(ptr->get_type() == type && ptr->is_high_standard() == high_standard && ptr->is_family() == family)
        {
            // return ptr->get_number();
            if(rooms.book_room(ptr->get_number(), period) && guest.get_money() >= (ptr->get_price()*(period.second-period.first+1))) {
                guest.set_room_number(ptr->get_number());
                guest.set_receipt(ptr->get_price()*(period.second-period.first+1) + guest.get_receipt());
                return ptr->get_number();
            }
        }
    }
    return 0;
}

void Hotel::add_dish(std::string type, std::string name, double price, double prep_cost, double prep_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens)
{
    Dish dish(name, price, prep_cost, prep_time, ingredients, allergens);
    if (type == "drink")
        menu.add_drink(dish);
    else
        menu.add_food(dish);
}

void Hotel::remove_dish(std::string type, std::string name)
{
    if(type == "drink")
        menu.remove_drink(name);
    else
        menu.remove_food(name);
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
    for(int i=0; i<30; i++)
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
                        if(room_ptr->is_reserved(current_checked_date)) return false;
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

void Hotel::choose_entertainment(std::string name, std::string PESEL, std::string type, int hour) {
    // for(Guest& g : guests)
    // {
    //     if(g->get_PESEL() == PESEL)
    //     {
    //         if(name == "taxi") g->order_taxi();
    //         if(name == "tidying") g->order_waking_up(0);
    //     }
    // }
}