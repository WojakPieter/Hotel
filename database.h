#include <iostream>
#include <vector>
#include <memory>
#include "room.h"
#include <cstdlib>
#pragma once

class Data_room
{
    std::vector<int> numbers_of_rooms;
    std::vector<std::unique_ptr<Room>> rooms;
public:
    std::vector<std::unique_ptr<Room>> get_rooms();
    std::vector<int> get_rooms_numbers();
    bool add_room(std::unique_ptr<Room>);
    bool remove_room(std::unique_ptr<Room>);
    bool book_room(int room_number, std::pair<Date, Date>);
    bool is_room_free(int room_number, std::pair<Date, Date>);
    std::vector<std::unique_ptr<Room>>::iterator begin();
    std::vector<std::unique_ptr<Room>>::iterator end();
};
