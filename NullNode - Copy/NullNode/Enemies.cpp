#include "Enemies.h"

void Enemies::DungeonUpdate(Character* player, Character* self) {
	int random = rand() % 100 + 1;
	if (random > 85) 
		MagicAttack(player);
	else
		Attack(player);
}

void Enemies::GetHit(int damage) {
	std::cout << "The ";
	Character::GetHit(damage);
}
//Attacks the player if they have magic.
//Magic is decremented after the attack.
void Enemies::MagicAttack(Character* player) {
	if (m_Stats.m_Magic > 0) {
		int damage = rand() % m_Stats.m_Magic + m_Stats.m_Strength + m_Stats.m_MaxMagic;
		player->GetHit(damage);
		m_Stats.m_Magic--;
	}
	else {
		std::cout << "\nBut they don't have the strength.\n";
	}
}