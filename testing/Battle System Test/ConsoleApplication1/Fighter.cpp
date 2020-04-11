#include "Fighter.h"
#include <random>
#include <ctime>

void Fighter::Attack(Fighter* target) {
	int damage = m_Stats.m_Strength + rand() % 6 + 1;
	std::cout << m_Name << " attacks " << target->GetName() << std::endl;
	target->GetHit(damage);
}

void Fighter::GetHit(int damage) {
	m_Stats.m_Health -= damage;
	std::cout << m_Name << " took " << damage << " points of damage!\n";
}

Fighter::~Fighter() {
	std::cout << std::endl << m_Name << " dies. \n\n";
}