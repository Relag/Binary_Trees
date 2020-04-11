#include "Hero.h"
#include <random>


Hero::Hero() {

	m_Stats.m_Agility = 2 + (rand() % 3);
	m_Stats.m_MaxHealth = 12 + (rand() % 6);
	m_Stats.m_Strength = 4 + (rand() % 2);
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Name = "Hero";
}

void Hero::heal(Hero* ally) {
	//placeholder to heal an ally.

}