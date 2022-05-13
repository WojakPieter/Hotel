#include "room.h"
#include <algorithm>

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

char Room::get_type()
{
    return type;
}

Room::Room(int number, bool high_standard, bool family)
{
    this->number = number;
    this->high_standard = high_standard;
    this->family = family;
    base_price = 150;
    base_area = 50;
}

void Room::set_parameters(double price_multiplier_low, double area_multiplier_low,
                          double price_multiplier_high, double area_multiplier_high)
{
    if(high_standard)
    {
        price = price_multiplier_high * base_price;
        area = area_multiplier_high * base_area;
    }
    else
    {
        price = price_multiplier_low * base_price;
        area = area_multiplier_low * base_area;
    }
}

OnePersonRoom::OnePersonRoom(int number, bool high_standard) : Room(number, high_standard, false)
{
    type = '1';
    Room::set_parameters(0.7, 0.9, 0.85, 1.1);
}

TwoPersonRoom::TwoPersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '2';
    Room::set_parameters(0.75, 0.9, 0.9, 1.15);
}

ThreePersonRoom::ThreePersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '3';
    Room::set_parameters(0.8, 0.95, 0.95, 1.2);
}

FourPersonRoom::FourPersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
{
    type = '4';
    Room::set_parameters(0.85, 1, 1, 1.2);
}

Studio::Studio(int number) : Room(number, false, false)
{
    type = 's';
    Room::set_parameters(0.8, 0.95, 0, 0);
}

Apartment::Apartment(int number) : Room(number, true, true)
{
    type = 'a';
    Room::set_parameters(0, 0, 1.4, 1.5);
}

bool Room::is_reserved(Date date)
{
    return(std::count(reserved_days.begin(), reserved_days.end(), date));
}

bool Room::is_high_standard()
{
    return high_standard;
}

bool Room::is_family()
{
    return family;
}

void Room::add_reserved_day(Date d)
{
    if(is_reserved(d)) return;
    reserved_days.push_back(d);
}

void Room::remove_reserved_day(Date d)
{
    if(!(is_reserved(d))) return;
    reserved_days.erase(std::find(reserved_days.begin(), reserved_days.end(), d));
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
