<<<<<<< HEAD
#ifndef CPP_PROJECT_WAITER_H
#define CPP_PROJECT_WAITER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Waiter : public Employee
{
    public:
    Waiter(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void bring_the_dish();
    // double receipt();
};
#endif
=======
#ifndef CPP_PROJECT_WAITER_H
#define CPP_PROJECT_WAITER_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

class Waiter : public Employee
{
    public:
    Waiter(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void bring_the_dish();
    // double receipt();
};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
