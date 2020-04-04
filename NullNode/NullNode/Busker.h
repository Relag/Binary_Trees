#pragma once
#include "NPC.h"
#include "Player.h"
class Busker :
	public Friendlies
{
public:
	Busker();
	void Talk(Player* player);
	void DungeonUpdate(Character* character, Character* enemy);
};

