#pragma once
#include "Maintenance.h"
#include "Movie.h"
#include "Schedule.h"


class Room {
private:
    string id;
    int seatsNumber;
    double price;
    Seat roomSeats[10][10];

public:

    Room() {

        id = "";

        seatsNumber = 0;

        price = 0;

        roomSeats[10][10];


    }

    Room(string);

    void setid(string);

    string getid();

};


class Seat {
private:
    string state;
    bool disponibilidad = false;

public:

    Seat() {




    }
    Seat(int seat, string state, bool status) {
     
        
        void seatscinema(int seat_id, string state,bool status);{
            string seats_state[10][10];


            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {

                seats_state[i][j] =    "D";

                }

            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    
                    bool status = false;
                    

                    if ( seats_state[i][j] == "D") {

                        bool status = true;





                    }
                    if (bool status = true) {








                    }



                }
                                                                       
                                                                       
                                                                       
                                                                       
                                                                       

            }

            
        }





    }





};


class Sale {
private:
    Booking booking;
    string idCustomer;
    string cardNumber;

public:

};
