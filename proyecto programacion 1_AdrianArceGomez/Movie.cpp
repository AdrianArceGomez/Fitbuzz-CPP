#include <iostream>
#include <string>
#include "Movie.h"



using namespace std;


 void addMovie() {
    int moviesNumber = 0;
    cout << "numero de pelis?? ";
    cin >> moviesNumber;

    if (moviesNumber < 1 || moviesNumber > 10) {
        return;
    }

    string name = "", country = "", time = "";
    int year = 0, ratings = 0;
   
            cout << "digite el nombre de la pelicula: ";
            cin >> name;
            cout << "digite el año de salida: ";
            cin >> year;
            cout << " digite el tiempo de pelicula: ";
            cin >> time;
            cout << "digite las reseñas: ";
            cin >> ratings;
            cout << "country: ";
            cin >> country;


           




     
    
};