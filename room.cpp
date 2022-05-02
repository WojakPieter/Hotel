#include "date.cpp"
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

OnePersonRoom::OnePersonRoom(int number, bool high_standard)
{
    this->number = number;
    this->high_standard = high_standard;
}

Studio::Studio(int number)
{
    this->number = number;
}



