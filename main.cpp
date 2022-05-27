#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

int main(){
	Date data(3, 9, 2020);
    Simulation play(3, data, "rooms.txt", "employees.txt", "simulation.txt", "menu.txt", "guests.txt");
	// std::cout << play.get_file_name();
	play.start();
}
