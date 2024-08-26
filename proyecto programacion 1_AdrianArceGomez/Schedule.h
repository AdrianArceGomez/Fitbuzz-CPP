#pragma once
#include "cinema.h"
#include "Movie.h"
#include "Room.h"


class Schedule {
private:
    string date;
    int startHour;
    int endHour;
    Movie movie;
    Room room;

public:

    Schedule() {


    }
    Schedule(string date, int starthour, int endhour) {

        void setdate();
        void setstartHour();
        void setendHour();


        string getdate();
        int getstartHour();
        int getendHour();


    }
    int schedule() {





    }
};