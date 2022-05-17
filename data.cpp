#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employees/employee.h"
#include "data.h"
#include <algorithm>


bool Data::add_employee(std::unique_ptr<Employee> ptr){
    for (auto& i: database){
        if (ptr -> getPESEL() == i -> getPESEL())
            return false;
    }
    database.push_back(std::move(ptr));
    return true;
}

bool Data::remove_employee(std::unique_ptr<Employee> ptr){
    try{
        database.erase(std::find(database.begin(), database.end(), ptr));
        return true;
    }
    catch(...){
        return false;
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
