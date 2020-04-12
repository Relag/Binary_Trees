#include "Player.h"

Player::Player() {
	m_Stats.m_Agility = 4 + (rand() % 3);
	m_Stats.m_MaxHealth = 12 + (rand() % 8);
	m_Stats.m_Strength = 3 + (rand() % 4);
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Name = "Player";
	isFoe = false;
}
