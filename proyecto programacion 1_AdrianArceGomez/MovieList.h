#pragma once
#include"Movie.h"


class Movielist {

private:

	Movie* Vectormovie;
	Movie movies;
	int size = 0;
	string movie = "";
	

public:


	int getsize();

	void addMovie(Movie newMovie);

	void copyVectormovie(Movie* newVector);


	


};