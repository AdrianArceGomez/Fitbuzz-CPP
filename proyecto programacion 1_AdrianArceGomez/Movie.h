#pragma once
#include "cinema.h"
#include "Room.h"
#include "Schedule.h"


class Movie {
private:
    string name;
    int year;
    string time;
    string country;
    int ratings;
    bool withData = false;

public:
    Movie() {

    }

    Movie(string name, int year, string time, string country, int ratings) {
        this->name = name;
        this->year = year;
        this->time = time;
        this->country = country;
        this->ratings = ratings;
    }


    void setName(string n) { name = n; }
    void setYear(int y) { year = y; }
    void setTime(string t) { time = t; }
    void setCountry(string c) { country = c; }
    void setRatings(int r) { ratings = r; }
    void setWithData(bool wd) { withData = wd; }

    string getName() { return name; }
    int getYear() { return year; }
    string getTime() { return time; }
    string getCountry() { return country; }
    int getRatings() { return ratings; }
    bool getWithData() { return withData; }


};
class Booking {
private:
    Schedule schedule;
    Seat bookSeats[5];
    double totalPrice;
    int bookingNumber;

public:

};
