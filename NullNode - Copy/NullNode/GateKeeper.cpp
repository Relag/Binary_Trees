#include "GateKeeper.h"

GateKeeper::GateKeeper() {
	m_Name = "The Gatekeeper";
	m_Description = "The Gatekeeper stands next forest entrance, a grim expression on his face. The large wooden gate firmly shut.\n";
	m_Affection = 0;
	m_Position.iX = 0;
	m_Position.iY = 5;
}

//For when player purposefully returns to the hub.
void GateKeeper::ReturnToHub(Player* player) {
	if (player->GetEnemiesKilled() > 0) {
		std::cout << "Gatekeeper: I see you've killed. Good work.\n";
		//Recieve one coin for each enemy killed. Add gold per Gatekeeper affection.
		std::cout << "You've recieved " << player->GetEnemiesKilled() << " coins.\n";
		player->AddMoney(player->GetEnemiesKilled() + m_Affection);
		//Recieve one experience for each enemy killed
		player->AddExperience(player->GetEnemiesKilled());
		player->RemoveEnemiesKilled();
		Sleep(2500);
		system("CLS");

		if (player->GetExperience() > 2 * player->GetLevel())
			player->LevelUp();

		if (player->gateKeeperPiece) {
			std::cout << "Gatekeeper: What do you have there? Is that...\n\n";
			Sleep(1500);
			std::cout << "The Gatekeeper took is piece. Their dour disposition softens slightly.";
			Sleep(2500);
			player->gateKeeperPiece = false;
			m_Affection++;
		}
	}
}

void GateKeeper::DungeonUpdate(Character* character, Character* enemy) {
	Attack(enemy);
}

void GateKeeper::Talk(bool &isNight, bool &inHub, Player* player) {
	if (!isNight)
		std::cout << "GateKeeper: (G)oing out? Try not to die.";
	else if (isNight && player->GetLevel() < 5)
		std::cout << "GateKeeper: I can't let you out at night. Maybe if you were stronger.";
	else if (isNight && player->GetLevel() >= 5)
		std::cout << "GateKeeper: You look like you can handle yourself. Be careful when you (G)o.";
	player->Gate(isNight, inHub);
}
