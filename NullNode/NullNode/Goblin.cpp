#include "Goblin.h"
//November 11: Created class
//November 14: Added DungeonUpdate for fighting
Goblin::Goblin(int level) {
	m_Stats.m_Level = level;
	m_Stats.m_MaxHealth = 5 + level; 
	m_Stats.m_MaxMagic = 1;
	m_Stats.m_Magic = m_Stats.m_MaxMagic;
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Stats.m_Agility = 3 + level;
	m_Stats.m_Strength = 1 + level;
	m_Name = "Goblin";
}

void Goblin::DungeonUpdate(Character* player) {
	Enemies::DungeonUpdate(player, this);
}

void Goblin::MagicAttack(Character* player) {
	std::cout << m_Name << " attacks.\n";
	Enemies::MagicAttack(player);
}

