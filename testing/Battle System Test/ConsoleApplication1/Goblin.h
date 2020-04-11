#pragma once
#include "Fighter.h"
class Goblin :
	public Fighter
{
public:
	Goblin();
	void Enrage(Goblin* ally);
};

