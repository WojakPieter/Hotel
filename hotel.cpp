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

bool Hotel::check_in(Guest guest, char type, bool high_standard, bool family, std::pair<Date,Date> period)
{
    for(auto& ptr : rooms.rooms)
    {
        if(ptr->get_type() == type && ptr->is_high_standard() == high_standard && ptr->is_family() == family)
        {
            if(rooms.book_room(ptr->get_number(), period) && guest.get_receipt() >= (ptr->get_price()*(period.second-period.first+1))) {
                guest.set_room_number(ptr->get_number()); 
                guest.set_receipt(ptr->get_price()*(period.second-period.first+1) + guest.get_receipt());
                return true;
            }
        }
    }
    return false;
}

void Hotel::add_dish(std::string type, std::string name, double price, double prep_cost, double prep_time, std::vector<Ingredient> ingredients, std::vector<std::string> allergens)
{
    Dish dish(name, price, prep_cost, prep_time, ingredients, allergens);
    if (type == "drink")
        menu.add_drink(dish);
    else
        menu.add_food(dish);
}

void Hotel::check_out(Guest guest)
{
    try{
        guests.erase(std::find(guests.begin(), guests.end(), guest));
    }
    catch(...){}
    increase_budget(guest.get_receipt());
    // zamowic sprzatanie u sprzataczki
}

bool Hotel::handing_out_salary()
{
    bool outgo = 0;
    for(auto& ptr : employees.database)
    {
        outgo += ptr->salary();
    }
    return decrease_budget(outgo);
}

void Hotel::creating_schedule(Date)
{
    for(auto& ptr : employees.database)
    {
        ;
    }
}

bool Hotel::shortening_the_stay(Guest guest, Date new_last_date)
{
    for(auto& room_ptr : rooms.rooms)
    {
        if(room_ptr->get_number() == guest.get_room_number())
        {
            double receipt = 0;
            if (guest.last_day >= new_last_date){
                double days = new_last_date - guest.last_day;
                receipt = receipt - days*room_ptr->get_price();
                while(guest.last_day > new_last_date)
                {
                    room_ptr->remove_reserved_day(new_last_date);
                    new_last_date++;
                }
            }
            else{
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
}

void Hotel::paying_the_bills()
{
    double bill = 0;
    if(current_date.get_day() == 20)
    {
        for(auto& room_ptr : rooms.rooms)
        {
            std::pair<double,double> func = room_ptr->get_maintain_costs_function();
            bill += (func.first * room_ptr->quantity_of_reserved_days(current_date - current_date.get_month_length(current_date.get_month()), current_date) + func.second);
        }
    }
}
