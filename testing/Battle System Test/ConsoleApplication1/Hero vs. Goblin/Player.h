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
	template <typename T>
	typename std::vector<T*>::iterator Menu(std::vector<T*>& choices, std::string intro = "");
};

