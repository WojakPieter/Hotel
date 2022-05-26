<<<<<<< HEAD
#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../guest.h"

class Bodyguard : public Employee
{
    public:
    Bodyguard(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void remove_guest(Guest, std::vector<Guest>);
};
#endif
=======
#ifndef CPP_PROJECT_BODYGUARD_H
#define CPP_PROJECT_BODYGUARD_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../guest.h"

class Bodyguard : public Employee
{
    public:
    Bodyguard(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void remove_guest(Guest, std::vector<Guest>);
};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
