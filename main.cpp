#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

int main(){
	Date data(3, 9, 2020);
    Simulation play("plik.txt", data, "jakis_plik.txt");
	// std::cout << play.get_file_name();
	play.start();
}