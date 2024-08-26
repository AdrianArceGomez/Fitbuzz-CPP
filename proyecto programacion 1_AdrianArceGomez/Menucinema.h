#pragma once
#include "cinema.h"
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"





class Menu {


private: 

	Movie movie;
	Room room;
	Sale sale;
	Booking booking;
	Schedule schedule;



public: 

	Menu() {


	}


	int menu() {
		int option;
		do {
			std::cout << "escoja la opcion a usa" << endl;
			std::cin >> option;

			if (option = 1) {




			}
			if (option = 2) {




			}


		} while (option != 0);
		




	}


};

