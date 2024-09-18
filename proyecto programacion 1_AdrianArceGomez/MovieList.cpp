#include <iostream>
#include "Movielist.h"

int Movielist::getsize() {


	return size;

}

void Movielist::addMovie(Movie newMovie) {
	Movie* newVectormovie = new Movie[size + 1];
	copyVectormovie(newVectormovie);
	size++;

	newVectormovie[size - 1] = newMovie;
	delete[] Vectormovie;
		Vectormovie = newVectormovie;
}
void Movielist::copyVectormovie(Movie* newVector) {
	for (int i = 0; i < size; i++) {
		newVector[i] = Vectormovie[i];
	}
}


