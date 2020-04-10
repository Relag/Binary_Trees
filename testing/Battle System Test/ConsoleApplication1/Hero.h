#pragma once
#include "Fighter.h"


class Hero :
	public Fighter
{
public:
	Hero();
	void heal(Hero* ally);
};

