#include "Room.h"

Room::Room(int depth, bool isNight) {
	//20 - 30% chance for an enemy to spawn based on depth.
	gateKeeperPiece = false;
	int random = rand() % 100 + 1;
	if (random > 80 - (depth * 2)) {
		//Enemy difficulty is based on time of day, and depth of tree.
		if (!isNight) {
			if (depth < 4)
				host = new Goblin(1);
			else {
				host = new Goblin(3);
				if (random > 90)
					gateKeeperPiece = true;
			}
		}
		else
			if (depth < 4)
				host = new Zombie(2);
			else {
				host = new Zombie(5);
				if (random > 90)
					gateKeeperPiece = true;
			}
	}
}