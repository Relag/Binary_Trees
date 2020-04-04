#pragma once
#include "Enemies.h"
class Goblin :
	public Enemies
{
public:
	Goblin(int level);
	void DungeonUpdate(Character* player);
	void MagicAttack(Character* player);
};

