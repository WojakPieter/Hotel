#include "date.hpp"
#include <iostream>
#include <vector>

class Room
{
    double area;
    double price;
    bool high_standard;
    bool family;
    int number;
    std::vector<std::pair<Date, Date>> reserved_days;

public:
    Room(int number, bool high_standard, bool family=false);
    double get_area();
    int get_price();
    bool is_high_standard();
    std::string get_number();
    virtual int get_number_of_required_workers()=0;
    virtual int get_number_of_beds()=0;
    bool is_reserved(Date);
};

class OnePersonRoom : public Room
{
    OnePersonRoom(int number, bool high_standard);
    virtual int get_number_of_required_workers()
    {
        if(high_standard) return 2;
        else return 1;
    }
    virtual int get_numbers_of_beds()
    {
        return 1;
    }
};

class TwoPersonRoom : public Room
{
    TwoPersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family);
    virtual int get_number_of_required_workers()
    {
        if(high_standard) return 4;
        else return 1;
    }
    virtual int get_numbers_of_beds()
    {
        if(family) return 1;
        else return 2;
    }
}

class ThreePersonRoom : public Room
{
    ThreePersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family)
    virtual int get_number_of_required_workers()
    {
        if(high_standard) return 3;
        else return 1;
    }
    virtual int get_numbers_of_beds()
    {
        if(family) return 2;
        else return 3;
    }
}

class FourPersonRoom : public Room
{
    ThreePersonRoom(int number, bool high_standard, bool family) : Room(number, high_standard, family);
    virtual int get_number_of_required_workers()
    {
        if(high_standard) return 4;
        else return 2;
    }
    virtual int get_numbers_of_beds()
    {
        if(family) return 2;
        else return 3;
    }
};

class Studio : public Room
{
    Studio(int number);
    virtual int get_number_of_required_workers()
    {
        return 5;
    }
    virtual int get_number_of_beds()
    {
        return 4;
    }
};

class Apartment : public Room
{
    Apartment(int number) : Studio(number);
     virtual int get_number_of_required_workers()
    {
        return 7;
    }
    virtual int get_number_of_beds()
    {
        return 5;
    }
};
