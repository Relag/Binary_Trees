#include "Busker.h"

Busker::Busker() {
	m_Name = "The Busker";
	m_Description = "Music fills the air. A busker stands next to a fountain.\n";
	m_Position.iX = 6;
	m_Position.iY = 6;
	m_Affection = 0;
}

void Busker::Talk(Player* player) {
	std::cout << "Would you like to (t)ip the busker?\n";
	player->Tip(this);
}

void Busker::DungeonUpdate(Character* character, Character* enemy) {
		Attack(enemy);
}