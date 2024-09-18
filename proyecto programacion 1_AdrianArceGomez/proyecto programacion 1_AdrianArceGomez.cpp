
#include <iostream>
#include "Room.h"
#include "Schedule.h"
#include "Maintenance.h"
#include "MenusCinema.h"




using namespace std;

int main()
{
	
	Generalmenu cosa;
	Menusaboutme about;

	cosa.Menu(about,1);


	string date;
	int startHour, endHour;

	cout << "digite el dia de la pelicula" << endl;
	cin >> date;
	cout << "digite la hora de inicio de la pelicula" << endl;
	cin >> startHour;
	cout << "digite la hora de salida de la pelicula" << endl;
	cin >> endHour;

	Schedule schedule = Schedule(date, startHour, endHour);


	cout << "la dia de la pelicula es: " << schedule.getdate() << endl;
	cout << "la hora de inicio es: " << schedule.getstartHour() << endl;
	cout << "la hora de salida es: " << schedule.getendHour() << endl;



}
