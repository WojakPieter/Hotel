#ifndef CPP_PROJECT_GUEST_H
#define CPP_PROJECT_GUEST_H
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

class Guest
{
    std::string first_name;
    std::string last_name;
    std::string email_adress;
    std::string PESEL;
    double money;
    int room_number;
    double receipt;

    public:
    Guest(std::string, std::string, std::string, std::string, double, int);
    
    // gettery i settery
    std::string get_first_name();
    std::string get_last_name();
    std::string get_email_adress();
    std::string get_PESEL();
    double get_money();
    double get_receipt();
    int get_room_number();

    void set_name(std::string, std::string);
    void set_email_adress(std::string);
    void set_PESEL(std::string);
    void set_money(double);
    void set_receipt(double);
    void set_room_number(int);

    void change_date_of_stay(Date, Date); //usuniecie z kalendarza pokoju oraz zwrot pewnej kwoty
    void order_taxi();
    void order_dish(std::string);
    void order_waking_up(int); // godzina podana i sprawdzic na ktorej zmianie 
    void order_tidying_room();
    // void book_room();

};
#endif