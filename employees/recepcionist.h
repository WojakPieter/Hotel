<<<<<<< HEAD
#ifndef CPP_PROJECT_RECEPCIONIST_H
#define CPP_PROJECT_RECEPCIONIST_H
#include <iostream>
#include <string>
#include <vector>
#include "../guest.h"
#include "../room.h"
#include "employee.h"

class Recepcionist : public Employee
{
    public:
    Recepcionist(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void book_room(int, Date, Date, Guest);
};
#endif
=======
#ifndef CPP_PROJECT_RECEPCIONIST_H
#define CPP_PROJECT_RECEPCIONIST_H
#include <iostream>
#include <string>
#include <vector>
#include "../guest.h"
#include "../room.h"
#include "employee.h"

class Recepcionist : public Employee
{
    public:
    Recepcionist(std::string, std::string, std::string, std::string, double);

    virtual void make_roster(std::vector<std::pair<Date, int>>);

    void book_room(int, Date, Date, Guest);
};
#endif
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
