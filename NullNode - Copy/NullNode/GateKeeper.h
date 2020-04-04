#pragma once
#include "NPC.h"
#include "Player.h"
class GateKeeper :
	public Friendlies
{
private:

public:
	void Talk(bool &isNight, bool &inHub, Player* player);
	GateKeeper();
	void ReturnToHub(Player* player);
	void DungeonUpdate(Character* character, Character* enemy);
	
};

