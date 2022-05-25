#ifndef CPP_PROJECT_ROOM_H
#define CPP_PROJECT_ROOM_H
#include <iostream>
#include <vector>
#include <map>
#include "date.h"

class Room
{
protected:
    char type;
    double area;
    double price;
    bool high_standard;
    bool family;
    int number;
    double base_price;
    double base_area;
    std::pair<double, double> maintain_costs_function;
    std::vector<Date> reserved_days;

public:
    Room(int number, bool high_standard, bool family);
    void add_reserved_day(Date);
    void remove_reserved_day(Date);
    int quantity_of_reserved_days(Date first_date, Date second_date);
    char get_type();
    double get_area();
    int get_price();
    bool is_family();
    bool is_high_standard();
    int get_number();
    std::pair<double,double> get_maintain_costs_function();
    virtual int get_number_of_required_workers()=0;
    virtual int get_number_of_beds()=0;
    virtual void set_parameters(double price_multiplier_high, double area_multiplier_high,
                        double price_multiplier_low, double area_multiplier_low);
    bool is_reserved_at_day(Date);
    bool is_reserved_in_period(std::pair<Date,Date>);

    //

    bool operator==(const Room& second_room)
    {
        return(number == second_room.number);
    }

    friend std::ostream& operator<<(std::ostream& os, Room&);
};

class OnePersonRoom : public Room
{
public:
    OnePersonRoom(int number, bool high_standard);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
};

class TwoPersonRoom : public Room
{
public:
    TwoPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
};

class ThreePersonRoom : public Room
{
public:
    ThreePersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
};

class FourPersonRoom : public Room
{
public:
    FourPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();

};

class Studio : public Room
{
public:
    Studio(int number);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
};

class Apartment : public Room
{
public:
    Apartment(int number);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
};

#endif
