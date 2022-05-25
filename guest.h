#ifndef CPP_PROJECT_GUEST_H
#define CPP_PROJECT_GUEST_H
#include <iostream>
#include <string>
#include <vector>
#include "database.h"
#include "menu.h"

class Guest
{
    std::string first_name;
    std::string last_name;
    std::string email_adress;
    std::string PESEL;
    double money;
    int room_number;
    int stay_length;
    double receipt;
    public:
    Date first_day, last_day;
    Guest(std::string, std::string, std::string, std::string, double);

    // gettery i settery
    std::string get_first_name();
    std::string get_last_name();
    std::string get_email_adress();
    std::string get_PESEL();
    int get_stay_length();
    double get_money();
    double get_receipt();
    int get_room_number();
    Date get_first_date();
    Date get_last_date();

    void set_name(std::string, std::string);
    void set_email_adress(std::string);
    void set_PESEL(std::string);
    void set_money(double);
    void set_receipt(double);
    void set_stay_length(int);
    void set_room_number(int);

    void add_money(double);
    bool subtract_money(double);
    bool change_date_of_stay(Date); //usuniecie z kalendarza pokoju oraz zwrot pewnej kwoty
    void order_taxi();
    void order_dish(std::string, Menu);
    void order_waking_up(int); // godzina podana i sprawdzic na ktorej zmianie
    void order_tidying_room();
    bool book_room(std::unique_ptr<Room> room, Date arrival_date, Date leave_date);

};
#endif