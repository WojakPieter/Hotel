<<<<<<< HEAD
#ifndef CPP_PROJECT_MAID_H
#define CPP_PROJECT_MAID_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../room.h"

class Maid : public Employee
{
    public:
    Maid(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    virtual void tidy_room(int number);
};
#endif
=======
#ifndef CPP_PROJECT_MAID_H
#define CPP_PROJECT_MAID_H
#include <iostream>
#include <string>
#include <vector>
#include "employee.h"
#include "../room.h"

class Maid : public Employee
{
    public:
    Maid(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void tidy_room();
};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
