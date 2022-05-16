#include "database.hpp"
#include <conio.h>
#include <algorithm>

bool Data_room::add_room(std::unique_ptr<Room> room_ptr)
{
    for(auto& i : rooms)
    {
        if(i == room_ptr) return false;
    }
    int nr = room_ptr -> get_number();
    rooms.push_back(std::move(room_ptr));
    numbers_of_rooms.push_back(nr);
    return true;
}

bool Data_room::remove_room(std::unique_ptr<Room> room_ptr)
{
    try
    {
       rooms.erase(std::find(rooms.begin(), rooms.end(), room_ptr));
       return true;
    }
    catch (...)
    {
        return false;
    }
}

std::vector<int> Data_room::get_rooms_numbers()
{
    return numbers_of_rooms;
}

bool Data_room::book_room(int room_number, std::pair<Date, Date> period)
{
    for(auto& ptr : rooms)
    {
        if(ptr->get_number() == room_number)
        {
            if(!(is_room_free(room_number, period))) return false;
            for(Date d=period.first; d<=period.second; d++)
            {
                ptr -> add_reserved_day(d);
            }
            return true;
        }
    }
    return false;
}

bool Data_room::is_room_free(int room_number, std::pair<Date, Date> period)
{
    for(auto& ptr : rooms)
    {
        if(ptr -> get_number() == room_number)
        {
           for(Date d=period.first; d<=period.second; d++)
            {
                if(ptr -> is_reserved(d)) return false;
            }
        }
    }
    return true;
}

std::vector<std::unique_ptr<Room>> Data_room::get_rooms()
{
    return std::move(rooms);
}
