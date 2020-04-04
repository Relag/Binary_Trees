#include "Zombie.h"
Zombie::Zombie(int level) {
	m_Stats.m_Level = level;
	m_Stats.m_MaxHealth = 8 + level;
	m_Stats.m_MaxMagic = 2 + level;
	m_Stats.m_Magic = m_Stats.m_MaxMagic;
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Stats.m_Agility = 0 + level;
	m_Stats.m_Strength = 1 + level;
	m_Name = "Zombie";
}

void Zombie::DungeonUpdate(Character* player) {
	Enemies::DungeonUpdate(player, this);
}

void Zombie::MagicAttack(Character* player) {
	std::cout << m_Name << " attacks.\n";
	Enemies::MagicAttack(player);
}