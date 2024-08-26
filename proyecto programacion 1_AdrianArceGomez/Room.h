#pragma once
#include "cinema.h"
#include "Movie.h"
#include "Schedule.h"


class Room {
private:
    int id;
    int seatsNumber;
    double price;
    Seat roomSeats[10][10];

public:

};


class Seat {
private:
    int id;
    string state;

public:


};


class Sale {
private:
    Booking booking;
    string idCustomer;
    string cardNumber;

public:

};
