#include <iostream>
// #include "hotel.h"
#include "simulation.h"
#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
     if(argc != 8)
     {
        std::cout << "Improper program agruments";
        exit(-1);
     }

 	std::string date_string = argv[1], day_str, month_str, year_str;
 	std::stringstream date_stream(date_string);
 	int day, month, year;
 	try
 	{
 	    if(!getline(date_stream, day_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
 	    if(!getline(date_stream, month_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
 	    if(!getline(date_stream, year_str, '.')) {std::cout << "Improper program agruments"; exit(-1);}
 	    day = atoi(day_str.c_str());
 	    month = atoi(month_str.c_str());
 	    year = atoi(year_str.c_str());
 	}
 	catch (...) {exit(-1);}
 	Date date(day,month,year);
	std::stringstream stream;
 	int days;
 	stream << argv[2];
 	stream >> days;

     Simulation play(days, date, argv[3], argv[4], argv[5], argv[6], argv[7]);
	// std::cout << play.get_file_name();
	play.start();
	Date data2(1,10,2020);
	//std::cout << data2 - 3 << std::endl;
}
