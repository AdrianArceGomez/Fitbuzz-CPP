#include "Schedule.h"




using namespace std;

Schedule::Schedule(): date(""),startHour(0),endHour(0) {
}

Schedule::Schedule(string _date, int _startHour, int _endHour) {

	date = _date;

	startHour = _startHour;

	endHour = _endHour;

}

void Schedule::setdate(string _date) {

	date = _date;

}
string Schedule::getdate() {

	return date;

}

void Schedule::setstartHour(int _startHour) {

	startHour = _startHour;

}
int Schedule::getstartHour() {

	return startHour;

}

void Schedule::setendHour(int _endHour) {

	endHour = _endHour;

}
int Schedule::getendHour() {

	return endHour;

}

void Schedule::makeschedule(int startHour, int endHour){





}


