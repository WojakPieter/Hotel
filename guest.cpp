#include <iostream>
#include "guest.h"
#include "menu.h"
#include <algorithm>
#include <vector>
#include <string>

Guest::Guest(std::string first_name_1, std::string last_name_1, std::string email_1, std::string pesel_1, double money_1, int room_number_1)
{
    first_name = first_name_1;
    last_name = last_name_1;
    email_adress = email_1;
    PESEL = pesel_1;
    money = money_1;
    room_number = room_number_1;
}

std::string Guest::get_first_name(){
    return first_name;
}

std::string Guest::get_last_name(){
    return last_name;
}

std::string Guest::get_email_adress(){
    return email_adress;
}

std::string Guest::get_PESEL(){
    return PESEL;
}

double Guest::get_money(){
    return money;
}

double Guest::get_receipt(){
    return receipt;
}

int Guest::get_room_number(){
    return room_number;
}

void Guest::set_name(std::string new_first_name, std::string new_last_name){
    first_name = new_first_name;
    last_name = new_last_name;
}

void Guest::set_email_adress(std::string new_email){
    email_adress = new_email;
}

void Guest::set_PESEL(std::string new_pesel){
    PESEL = new_pesel;
}

void Guest::set_money(double new_money){
    money = new_money;
}

void Guest::set_receipt(double new_receipt){
    receipt = new_receipt;
}

void Guest::set_room_number(int new_number){
    room_number = new_number;
}

void Guest::order_taxi(){
    // wczytac z pliku jakis cennik atrakcji
    int price = 100;
    if ((price+receipt) > money)
        return;
    receipt += price;
}

void Guest::change_date_of_stay(Date old_last_date, Date new_last_date){
    if (old_last_date >= new_last_date){
        double days = new_last_date - old_last_date;
        receipt = receipt - days*room.get_price();
        while(old_last_date > new_last_date)
        {
            room.remove_day(new_last_date);
            new_last_date += 1;
        }
    }
    else{
        double days = old_last_date - new_last_date;
        if(days*room.get_price()+receipt >= money)
        {
            receipt += days*room.get_price();
            while(old_last_date <= new_last_date)
            {
                room.add_day(old_last_date);
                old_last_date += 1;
            }
        }
    }
} //usuniecie z kalendarza pokoju oraz zwrot pewnej kwoty

void Guest::order_dish(std::string dish_name, Menu menu){
    int price = menu.find_price(dish_name);
    if ((price+receipt) > money)
        return;
    receipt += price;
}

void Guest::order_waking_up(int hour){
    int price = 10;
    if ((price+receipt) > money)
        return;
    receipt += price;
} // godzina podana i sprawdzic na ktorej zmianie

void Guest::order_tidying_room(){
    int price = 30;
    if ((price+receipt) > money)
        return;
    receipt += price;
}

// void Guest::book_room(Room room){
//     room_number = room.get_number();
//     receipt += room.get_price();
// }

