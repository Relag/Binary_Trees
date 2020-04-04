#pragma once
#include "Player.h"
class NPC :
	public Character
{
private:
	int iAffection;


public:
	int GetAffection() { return iAffection; }
	void IterateAffection();
	virtual void Talk(Player* player) = 0;

};

