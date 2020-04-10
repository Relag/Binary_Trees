#include "Goblin.h"
#include <random>
#include <ctime>

Goblin::Goblin() {
	srand(time(NULL));
	m_Stats.m_Agility = 3 + (rand() % 3);
	m_Stats.m_MaxHealth = 10 + (rand() % 5);
	m_Stats.m_Strength = 2 + (rand() % 5);
}

void Goblin::Enrage(Goblin* ally) {
	//placeholder to strngthen an ally's attack
}