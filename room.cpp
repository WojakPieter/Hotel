#include "room.hpp"

double Room::get_area()
{
    return area;
}

int Room::get_price()
{
    return price;
}

int Room::get_number()
{
    return number;
}

Room::Room(int number, bool high_standard, bool family)
{
    this->number = number;
    this->high_standard = high_standard;
    this->family = family;
}

OnePersonRoom::OnePersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, false)
{
    this->set_parameters();
}

bool Room::is_reserved(Date date)
{
    for(std::pair<Date, Date> interval : reserved_days)
    {
        if(date <= interval.second && date >= interval.first)   return true;
    }
    return false;
}

bool Room::is_high_standard()
{
    return high_standard;
}

void OnePersonRoom::set_parameters()
{
        if(high_standard)
        {
            area = 25;
            price = 100;
        }
        else
        {
            area = 15;
            price = 80;
        }
}

int OnePersonRoom::get_number_of_beds()
{
    return 1;
}

int OnePersonRoom::get_number_of_required_workers()
{
    if(high_standard) return 2;
    else return 1;
}

void TwoPersonRoom::set_parameters()
{
        if(high_standard)
        {
            area = 35;
            price = 110;
        }
        else
        {
            area = 25;
            price = 90;
        }
}

int TwoPersonRoom::get_number_of_beds()
{
    if(family) return 1;
    else return 2;
}

int TwoPersonRoom::get_number_of_required_workers()
{
    if(high_standard) return 3;
    else return 1;
}

void ThreePersonRoom::set_parameters()
{
        if(high_standard)
        {
            area = 55;
            price = 130;
        }
        else
        {
            area = 45;
            price = 100;
        }
}

int ThreePersonRoom::get_number_of_beds()
{
    if(family) return 2;
    else return 3;
}

int ThreePersonRoom::get_number_of_required_workers()
{
    if(high_standard) return 4;
    else return 1;
}

void FourPersonRoom::set_parameters()
{
        if(high_standard)
        {
            area = 65;
            price = 160;
        }
        else
        {
            area = 45;
            price = 120;
        }
}

int FourPersonRoom::get_number_of_beds()
{
    if(family) return 3;
    else return 4;
}

int FourPersonRoom::get_number_of_required_workers()
{
    if(high_standard) return 4;
    else return 2;
}

void Studio::set_parameters()
{
        area = 45;
        price = 120;
}

int Studio::get_number_of_beds()
{
    return 4;
}

int Studio::get_number_of_required_workers()
{
    return 5;
}

void Apartment::set_parameters()
{
    area = 80;
    price = 200;
}

int Apartment::get_number_of_beds()
{
    return 1;
}

int Apartment::get_number_of_required_workers()
{
    return 7;
}
