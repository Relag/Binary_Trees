#include "Player.h"
#include <Windows.h>
#include <conio.h>

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
	
	
	std::vector<Fighter*>::iterator toAttack;
	toAttack = Menu(enemies);
	Attack(*toAttack);
}

void Player::Attack(Fighter* target) {
	int damage = m_Stats.m_Strength + rand() % 6 + 1;
	target->GetHit(damage);
}

template <typename T>
typename std::vector<T*>::iterator Player::Menu(std::vector<T*>& choices, std::string intro) {
	
	typename std::vector<T*>::iterator iter = choices.begin();
	int cDirection = 0;
	while (cDirection != '\r') {
		std::cout << intro << std::endl;
		cDirection = 0;
		for (int i = 0; i < choices.size(); i++) {
			if ((**iter) == (*choices[i])) {
				std::cout << "-->";
			}
			std::cout << "\t" << (*choices[i]) << std::endl;
		}
		Sleep(50);
		cDirection = _getch();
		if (cDirection == 80 && iter != choices.end() - 1)
			iter++;
		else if (cDirection == 72 && iter != choices.begin())
			iter--;

		system("CLS");
	}
	return iter;
}