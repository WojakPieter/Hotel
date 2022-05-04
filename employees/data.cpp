#include <iostream> 
#include <vector>
#include <string>
#include <memory>
#include <vector>
#include "employee.h"
#include "data.h"
#include <algorithm>


void data::add_employee(std::unique_ptr<employee> ptr){
    for (auto& i: database){
        if (ptr -> getPESEL() == i -> getPESEL()) 
            return;
    }
    database.push_back(std::move(ptr));
}

void data::remove_employee(std::unique_ptr<employee> ptr){
    try{
        database.erase(std::find(database.begin(), database.end(), ptr));
    }
    catch(...){}
}

double data::working_hours(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> getPESEL()) 
            return i -> workingHours();
    }
    return -1;
}

double data::salary(std::string PESEL){
    for (auto& i: database){
        if (PESEL == i -> getPESEL()) 
            return i -> salary();
    }
    return -1;
}

void data::print_rates()
{
    std::cout << "Pracownicy i ich pensje godzinne: " << std::endl;
     for (auto& i: database){
        std::cout << i -> getPESEL() << "  " << i -> getHourlyRate() << std::endl;
    }
}

int data::get_size(){
    return database.size();
}