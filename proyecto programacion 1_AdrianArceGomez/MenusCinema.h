#pragma once
#include "MovieList.h"
#include "RoomList.h"
#include "Schedule.h"
#include "Maintenance.h"

using namespace std;



class Generalmenu {
private:

	Menusaboutme Menuaboutme;

	int choise = 0;


public:

	void Menu(Menusaboutme Menuaboutme,int choise);

	void erroroption(void Menu()) ;



};

class Menusaboutme {


private:

	string name = "Adrian Arce Gomez";


public: 

	void menuaboutme();

	void erroroptions(void menuaboutme());
	


};

class MenuMaintenance {
private: 

	Movielist Movies;

	RoomList Rooms;


public:


};

