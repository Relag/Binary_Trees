#pragma once
//November 14: Created class
#include "Enemies.h"
class Zombie :
	public Enemies
{
public:
	Zombie(int level);
	void DungeonUpdate(Character* player);
	void MagicAttack(Character* player);
};

