#pragma once
#include "Fighter.h"
class Goblin :
	public Fighter
	
{
private:
	const int POWER_UP_BY = 4;
	int TurnsSincePowerUp;
	void DePowerUp();
public:
	Goblin();
	void Enrage(std::vector<Fighter*> ally);
	void Act(std::vector<Fighter*> Allies, std::vector<Fighter*> Enemies);
	void PowerUp();
	bool isEnraged() { return TurnsSincePowerUp > 0; }
};

