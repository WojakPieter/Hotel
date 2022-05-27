#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

int main(){
	Date data(3, 9, 2020);
    Simulation play("plik.txt", data, "rooms.txt", "employees.txt", "simulation.txt", "menu.txt");
	// std::cout << play.get_file_name();
	play.start();
<<<<<<< HEAD
}
=======
}
>>>>>>> 1d79bc9a06b5f03e9152b25058483c8aff88215f
