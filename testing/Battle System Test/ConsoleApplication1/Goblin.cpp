#include "Goblin.h"
#include <random>

Goblin::Goblin() {
	m_Stats.m_Agility = 3 + (rand() % 3);
	m_Stats.m_MaxHealth = 10 + (rand() % 5);
	m_Stats.m_Strength = 2 + (rand() % 6);
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Name = "Goblin";
	isFoe = true;
	TurnsSincePowerUp = 0;
}

void Goblin::Enrage(std::vector<Fighter*> ally) {
	//placeholder to strengthen an ally's attack
	int randNum = rand() % ally.size();
	//Will only enrage self is ally is dead or already enraged.
	do {
		randNum = rand() % ally.size();
	} while (ally[randNum]->isEnraged());
	ally[randNum]->PowerUp();
	std::cout << std::endl << ally[randNum]->GetName() << " became enraged!" << std::endl;
}

void Goblin::Act(std::vector<Fighter*> Allies, std::vector<Fighter*> Enemies) {
	int randNum = (rand() % 10) + 1;
	if (TurnsSincePowerUp > 0) {
		TurnsSincePowerUp--;
		Attack(Enemies);
	}
	else if (randNum < 9) {
		Enrage(Allies);
	}
	else {
		Attack(Enemies);
	}
}

void Goblin::PowerUp() {
	m_Stats.m_Strength += POWER_UP_BY;
	TurnsSincePowerUp = 2;
}

void Goblin::DePowerUp() {
	m_Stats.m_Strength -= POWER_UP_BY;
}