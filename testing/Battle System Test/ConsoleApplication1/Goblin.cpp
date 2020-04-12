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

void Goblin::Enrage(Goblin* ally) {
	//placeholder to strngthen an ally's attack
}

void Goblin::Act(std::vector<Fighter*> Allies, std::vector<Fighter*> Enemies) {
	if (TurnsSincePowerUp > 0) {
		TurnsSincePowerUp--;
		Attack();
	}
}

void Goblin::PowerUp() {
	m_Stats.m_Strength += POWER_UP_BY;
	TurnsSincePowerUp = 2;
}

void Goblin::DePowerUp() {
	m_Stats.m_Strength -= POWER_UP_BY;
}