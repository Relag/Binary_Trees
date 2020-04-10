#pragma once
#include "Fighter.h"
class Goblin :
	public Fighter
{
	Goblin();
	void Enrage(Goblin* ally);
};

