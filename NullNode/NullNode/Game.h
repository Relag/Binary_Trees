#pragma once
#ifndef GAME_H
#define GAME_H

#include <list>
#include "Zombie.h"
#include "Goblin.h"
#include "Player.h"
#include "Busker.h"
#include "GateKeeper.h"
#include "Tree.h"
#include "Node.h"
#include <list>
#include <Windows.h>

class Game
{
private:
	
	void Render(Friendlies* Busker, Player* player);
	//void Stats();
	void Battle(Character* foe, Player* player);
	void Hub(bool& inHub, Player* player, Busker* busker, GateKeeper* gateKeeper);
	void Dungeon(bool& inHub, Player* player, GateKeeper* gateKeeper);
	void Clean();

public:
	void Init();
	bool isNight;
	bool inHub;
	bool playing;
};

#endif // !GAME_H