#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

<<<<<<< HEAD
int main(int argc, char* argv[]){
     if(argc != 7)
     {
         std::cout << "Improper program agruments";
        exit(-1);
     }
 	Date data(3, 9, 2020);
	std::stringstream stream;
 	int days;
 	stream << argv[1];
 	stream >> days;

     Simulation play(days, data, argv[2], argv[3], argv[4], argv[5], argv[6]);
	// std::cout << play.get_file_name();
	play.start();
 }
=======
// int main(int argc, char* argv[]){
//     if(argc != 7)
//     {
//         std::cout << "Improper program agruments";
//         exit(-1);
//     }
// 	Date data(3, 9, 2020);
// 	std::stringstream stream;
// 	int days;
// 	stream << argv[1];
// 	stream >> days;
	
//     Simulation play(days, data, argv[2], argv[3], argv[4], argv[5], argv[6]);
// 	// std::cout << play.get_file_name();
// 	play.start();
// }
>>>>>>> 83fd4d4fc8d2f002e0ab9ad446d19128a714d419
