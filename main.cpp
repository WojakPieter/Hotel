#include "simulation.h"

int main()
{
	Simulation s("plik.txt", Date(15,10,2020), "rooms.txt", "employees.txt");
	s.start();
}
