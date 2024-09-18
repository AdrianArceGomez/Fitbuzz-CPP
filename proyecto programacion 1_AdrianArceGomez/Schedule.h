#pragma once
#include <iostream>
#include <string>



class Schedule {
private: 

	string date;
	int startHour;
	int endHour;
	

public:

	Schedule();

	Schedule(string _date, int _starthour, int _endhour );
	//Setters
	void setdate(string);
	void setstartHour(int);
	void setendHour(int);

	//Getters
	string getdate();
	int getstartHour();
	int getendHour();

	void makeschedule( int startHour, int endHour);

	

};