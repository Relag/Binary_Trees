#include "Character.h"

//Basic attack function. Inherits to Enemies and Friendlies
void Character::Attack(Character* target) {
	//srand(time(NULL));
	int damage = rand() % m_Stats.m_Strength + m_Stats.m_Strength;
	std::cout << m_Name << " attacks.\n";
	target->GetHit(damage);
	
}
//Function to take damage.
void Character::GetHit(int damage) {
	m_Stats.m_Health -= damage;
	std::cout << m_Name << " takes " << damage << " damage.\n";
}

void Character::Heal(int heal) {
	m_Stats.m_Health += heal;
	if (m_Stats.m_Health > m_Stats.m_MaxHealth) {
		m_Stats.m_Health = m_Stats.m_MaxHealth;
	}
	std::cout << m_Name << " healed " << heal << " health.\n";
}

void Character::ReplenishMagic(int amount) {
	m_Stats.m_Magic += amount;
	if (m_Stats.m_Magic > m_Stats.m_MaxMagic)
		m_Stats.m_Magic = m_Stats.m_MaxMagic;
}

void Character::DisplayDungeonStats() {
	std::cout << m_Name << ": \n";
	std::cout << "\tHealth: " << m_Stats.m_Health << "/" << m_Stats.m_MaxHealth;

	std::cout << "\tMagic: " << m_Stats.m_Magic << "/" << m_Stats.m_MaxMagic << std::endl;
}

void Character::DisplayStats() {
	DisplayDungeonStats();
	std::cout << "Strength: " << m_Stats.m_Strength << std::endl;
	std::cout << "Agility: " << m_Stats.m_Agility << std::endl;
}

Character::~Character() {
	std::cout << "The " << m_Name << " lies dead.\n";
}