#include "date.cpp"
#include <iostream>
#include <vector>

class Room
{
protected:
    double area;
    double price;
    bool high_standard;
    bool family;
    int number;
    std::vector<std::pair<Date, Date>> reserved_days;

public:
    Room(int number, bool high_standard, bool family);
    double get_area();
    int get_price();
    bool is_high_standard();
    int get_number();
    virtual int get_number_of_required_workers()=0;
    virtual int get_number_of_beds()=0;
    virtual void set_parameters()=0;
    bool is_reserved(Date);

    bool operator==(const Room& second_room)
    {
        return(number == second_room.number);
    }
};

class OnePersonRoom : public Room
{
public:
    OnePersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();
};

class TwoPersonRoom : public Room
{
public:
    TwoPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();
};

class ThreePersonRoom : public Room
{
public:
    ThreePersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();
};

class FourPersonRoom : public Room
{
public:
    FourPersonRoom(int number, bool high_standard, bool family);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();

};

class Studio : public Room
{
public:
    Studio(int number);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();
};

class Apartment : public Room
{
public:
    Apartment(int number);
    virtual int get_number_of_required_workers();
    virtual int get_number_of_beds();
    virtual void set_parameters();
};
