#include <iostream>
#include "Room.h"


Room::Room() {

	id = "";


}

Room::Room(string _id) {

	id = _id;

}

void Room::setid(string _id) {


	id = _id;

}

string Room::getid() {

	return id;

}

void doid(string id, string seatsid, int numberid) {

	int numberid = 1;
	string seatsid[10][10];
	string id = "";

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			seatsid = "A" + to_string(numberid);


		}

	}



}
