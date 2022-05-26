<<<<<<< HEAD
#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

int main(){
	Date data(3, 9, 2020);
    Simulation play("plik.txt", data, "rooms.txt", "employees.txt", "simulation.txt");
	// std::cout << play.get_file_name();
	play.start();
=======
#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

int main(){
	Date data(3, 9, 2020);
    Simulation play("plik.txt", data, "rooms.txt", "employees.txt", "simulation.txt");
	// std::cout << play.get_file_name();
	play.start();
>>>>>>> 9b18161f2247526bcb7974c2f5760727eb8a5e12
}