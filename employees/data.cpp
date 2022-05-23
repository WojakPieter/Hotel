#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"
#include "data.h"
#include <algorithm>


bool Data::add_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {

    std::unique_ptr<Employee> new_employee;
    if (type == "barman") {
        new_employee = std::make_unique<Barman>(first_name, second_name, email_adress, pesel, hourly_rate);
        database.push_back(std::move(new_employee));
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
    return true;
    }

    if (type == "bodyguard") {
        new_employee = std::make_unique<Bodyguard>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));

    return true;
    }

    if (type == "cook") {
        new_employee = std::make_unique<Cook>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));
    return true;
    }

    if (type == "maid") {
        new_employee = std::make_unique<Maid>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));
    return true;
    }

    if (type == "manager") {
        new_employee = std::make_unique<Manager>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));
    return true;
    }

    if (type == "recepcionist") {
        new_employee = std::make_unique<Recepcionist>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));
    return true;
    }

    if (type == "waiter") {
        new_employee = std::make_unique<Waiter>(first_name, second_name, email_adress, pesel, hourly_rate);
        for (auto& i: database) {
        if (new_employee -> get_PESEL() == i -> get_PESEL())
            return false;
    }
        database.push_back(std::move(new_employee));
    return true;
    }
    return true;
}

bool Data::remove_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate){
    std::unique_ptr<Employee> ptr = make_employee_pointer(type,first_name,second_name,email_adress,pesel,hourly_rate);
    try{
        database.erase(std::find(database.begin(), database.end(), ptr));
        return true;
    }
    catch(...){
        return false;
    }
}

std::unique_ptr<Employee> Data::make_employee_pointer(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate){
    if (type == "barman") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Barman>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "bodyguard") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Bodyguard>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "cook") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Cook>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "maid") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Maid>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "manager") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Manager>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "recepcionist") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Recepcionist>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }

    if (type == "waiter") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Waiter>(first_name, second_name, email_adress, pesel, hourly_rate);
        return std::move(new_employee);
    }
}

double Data::working_hours(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> get_PESEL())
            return i -> working_hours();
    }
    std::cout << "This employee does not exist.\n";
    return 0;
}

double Data::salary(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> get_PESEL())
            return i -> salary();
    }
    std::cout << "This employee does not exist.\n";
    return 0;
}

void Data::print_rates()
{
    if (get_size() == 0)
        std::cout << "Lack of employees.";

    else{
    std::cout << "Employees and their rates: " << std::endl;
    for (auto& i: database){
        std::cout << i -> get_first_name() << "  ";
        std::cout << i -> get_last_name() << "  ";
        std::cout << i -> get_Hourly_rate() <<"zl \n";
    }
    }
}

bool Data::print_employee(std::string pesel){
    for (auto& i: database){
        if (pesel == i -> get_PESEL()) {
            std::cout << "First name: " << i -> get_first_name() << std::endl;
            std::cout << "Last name: " << i -> get_last_name() << std::endl;
            std::cout << "Email adress: " << i -> get_email_adress() << std::endl;
            std::cout << "PESEL: " << i -> get_PESEL() << std::endl;
            std::cout << "Hourly rate: " << i -> get_Hourly_rate() << std::endl;
            return true;
        }
    }
    return false;
}

int Data::get_size(){
    return database.size();
}

bool Data::edit_employee(std::string pesel, std::string new_first_name, std::string new_last_name, std::string new_email){
    for (auto& i: database){
        if (pesel == i -> get_PESEL()){
            i -> set_name(new_first_name, new_last_name);
            i -> set_email_adress(new_email);
            i -> set_hourly_rate();
            return true;
        }
    }
    return false;
}

void Data::set_employee_rate(std::string pesel, double newRate){
    for (auto& i: database){
        if (pesel == i -> get_PESEL())
            i -> set_Hourly_rate(newRate);
    }
}

bool Data::employee_roster(std::string pesel){
    for (auto& i: database){
        if (pesel == i -> get_PESEL()){
            //i -> print_roster();
            return true;
        }
    }
    return false;
}

bool Data::make_employee_roster(std::string pesel, std::vector<std::pair<Date, int>> dates){
    for (auto& i: database){
        if (pesel == i -> get_PESEL()){
            i -> make_roster(dates);
            return true;
        }
    }
    return false;
}

void Data::clear()
{
    database.clear();
}

std::vector<std::unique_ptr<Employee>>::iterator Data::begin()
{
    return database.begin();
}

std::vector<std::unique_ptr<Employee>>::iterator Data::end()
{
    return database.end();
}
