#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"
#include "data.h"
#include <algorithm>


bool Data::add_employee(std::string type, std::string first_name, std::string second_name, std::string email_adress, std::string pesel, double hourly_rate) {
    
    std::unique_ptr<Employee> ptr = make_employee_pointer(type,first_name,second_name,email_adress,pesel,hourly_rate);
    for (auto& i: database) {
        if (ptr -> getPESEL() == i -> getPESEL()) 
            return false;
    }
    database.push_back(std::move(ptr));
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
        return new_employee;
    }

    if (type == "bodyguard") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Bodyguard>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }

    if (type == "cook") {   
        std::unique_ptr<Employee> new_employee = std::make_unique<Cook>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }
        
    if (type == "maid") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Maid>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }
        
    if (type == "manager") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Manager>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }
        
    if (type == "recepcionist") {    
        std::unique_ptr<Employee> new_employee = std::make_unique<Recepcionist>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }

    if (type == "waiter") {
        std::unique_ptr<Employee> new_employee = std::make_unique<Waiter>(first_name, second_name, email_adress, pesel, hourly_rate);
        return new_employee;
    }
}

double Data::working_hours(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> getPESEL()) 
            return i -> workingHours();
    }
    std::cout << "This employee does not exist.\n";
    return 0;
}

double Data::salary(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> getPESEL()) 
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
        std::cout << i -> getFirstName() << "  ";
        std::cout << i -> getLastName() << "  ";
        std::cout << i -> gethourlyRate() <<"zl \n";
    }
    }
}

bool Data::print_employee(std::string pesel){
    for (auto& i: database){
        if (pesel == i -> getPESEL()) {
            std::cout << "First name: " << i -> getFirstName() << std::endl;
            std::cout << "Last name: " << i -> getLastName() << std::endl;
            std::cout << "Email adress: " << i -> getEmailAdress() << std::endl;
            std::cout << "PESEL: " << i -> getPESEL() << std::endl;
            std::cout << "Hourly rate: " << i -> gethourlyRate() << std::endl;
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
        if (pesel == i -> getPESEL()){
            i -> setName(new_first_name, new_last_name);
            i -> setEmailAdress(new_email);
            i -> setHourlyRate();
            return true;
        }
    }
    return false;
}

void Data::set_employee_rate(std::string pesel, double newRate){
    for (auto& i: database){
        if (pesel == i -> getPESEL())
            i -> sethourlyRate(newRate);
    }
}

bool Data::employee_roster(std::string pesel){
    for (auto& i: database){
        if (pesel == i -> getPESEL()){
            i -> printRoster();
            return true;
        }
    }
    return false;
}

bool Data::make_employee_roster(std::string pesel, std::vector<std::pair<Date, int>> dates){
    for (auto& i: database){
        if (pesel == i -> getPESEL()){
            i -> makeRoster(dates);
            return true;
        }
    }
    return false;
}