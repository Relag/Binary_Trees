#pragma once
#include "Fighter.h"

class Player :
	public Fighter
{
public:
	Player();
	~Player();
	void Act(std::vector<Fighter*> allies, std::vector<Fighter*> enemies);
	void Attack(Fighter* target);
};

