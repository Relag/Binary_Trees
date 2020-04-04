#pragma once
#include "Character.h"
class Enemies :
	public Character
{
public:
	
	void DungeonUpdate(Character* player, Character* self);
	void GetHit(int damage);
	virtual void MagicAttack(Character* player);
};

