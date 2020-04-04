#pragma once
#include <ctime>
#include <random>
//November 11: Created class for dungeon navigation
//November 15: Randomized enemy placement
//November 16: Created zombies for nighttime class.

#include "Goblin.h"
#include "Zombie.h"
class Room
{
public:
	//Call for tree creation
	Room(int depth, bool isNight);
	//Call for hub creation
	Character* host = nullptr;
	bool gateKeeperPiece;
};

