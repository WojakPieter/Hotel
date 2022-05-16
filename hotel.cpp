#include "hotel.h"

Hotel::Hotel(std::string name, int stars, double budget, Data employees, Data_room rooms, Menu menu)
{
    ;
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

bool Hotel::check_in(Guest guest, char type, bool high_standard, bool family, std::pair<Date,Date> period)
{
    for(auto& ptr : rooms.rooms)
    {
        if(ptr->get_type() == type && ptr->is_high_standard() == high_standard && ptr->is_family() == family)
        {
            if(rooms.book_room(ptr->get_number(), period)) {guest.set_room_number(ptr->get_number()); return true;}
        }
    }
    return false;
}

void Hotel::check_out(Guest guest)
{
    ;
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

void Hotel::creating_schedule()
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
