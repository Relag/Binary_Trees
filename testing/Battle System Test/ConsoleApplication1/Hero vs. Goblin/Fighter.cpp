#include "Fighter.h"
#include <random>
#include <ctime>

//Generic function for all AI combatants. Pass in vector of opposing force for targeting
void Fighter::Attack(std::vector<Fighter*> target) {
	int damage = m_Stats.m_Strength + rand() % 6 + 1;
	int randNum = rand() % target.size();
	std::cout << std::endl << m_Name << " attacks " << target[randNum]->GetName() << std::endl;
	target[randNum]->GetHit(damage);
}

void Fighter::GetHit(int damage) {
	m_Stats.m_Health -= damage;
	std::cout << m_Name << " took " << damage << " points of damage!\n";
}

bool Fighter::isEnraged()
{
	return false;
}

void Fighter::PowerUp()
{
}

Fighter::~Fighter() {
	std::cout << std::endl << m_Name << " dies. \n\n";
}

std::ostream& operator<<(std::ostream& os, const Fighter& fighter) {
	os << fighter.m_Name;
	return os;
}

bool Fighter::operator==(const Fighter& fighter) {
	return m_Name == fighter.m_Name;
}

