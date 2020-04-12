#include "Player.h"

Player::Player() {
	m_Stats.m_Agility = 4 + (rand() % 3);
	m_Stats.m_MaxHealth = 12 + (rand() % 8);
	m_Stats.m_Strength = 3 + (rand() % 4);
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Name = "Player";
	isFoe = false;
}

Player::~Player() {
	std::cout << "\nYou have died.\n";
}

void Player::Act(std::vector<Fighter*> allies, std::vector<Fighter*> enemies) {
	int toAttack;
	for (int i = 0; i < enemies.size(); i++) {
		std::cout << i << " " << enemies[i]->GetName();
	}
	std::cin >> toAttack;
	Attack(enemies[toAttack]);
}

void Player::Attack(Fighter* target) {
	int damage = m_Stats.m_Strength + rand() % 6 + 1;
	target->GetHit(damage);
}