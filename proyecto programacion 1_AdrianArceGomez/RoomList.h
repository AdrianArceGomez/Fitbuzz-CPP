#pragma once
#include "Room.h"


class RoomList {
public:

	Room* RoomVector;

	int numbersofrooms;

private:

	void addRoom(Room newroom);

	void copyVectorRooom(Room* newroom);

};
