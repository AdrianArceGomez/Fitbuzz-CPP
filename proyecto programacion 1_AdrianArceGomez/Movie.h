#pragma once
#include <string>
using namespace std;

class Movie {
private:
    std::string name;
    int year;
    std::string time;
    std::string country;
    int ratings;
    bool withData;
    int cinemaMovies[10];

public:
    Movie() {

        name = "";

        year = 0;

        time = "";

        country = "";

        ratings = 0;

        withData = false;

    };

    Movie(std::string _name, int _year, std::string _time, std::string _country, int _ratings)
        : name(_name), year(_year), time(_time), country(_country), ratings(_ratings), withData(true) {
    
        std::string _name;
    
    
    
    
    }

    void setName(const std::string& n) { name = n; }
    void setYear(int y) { year = y; }
    void setTime(const std::string& t) { time = t; }
    void setCountry(const std::string& c) { country = c; }
    void setRatings(int r) { ratings = r; }
    void setWithData(bool wd) { withData = wd; }

    std::string getName() const { return name; }
    int getYear() const { return year; }
    std::string getTime() const { return time; }
    std::string getCountry() const { return country; }
    int getRatings() const { return ratings; }
    bool getWithData() const { return withData; }

   
};
