//November 5: created class. created hub map.
//November 9: added bools isNight and inHub
//November 15 Added points of interest to the map.

#include "Game.h"

void Game::Init() {
	//Bools for game state (dungeon or hub) and time of day (night or day).
	inHub = true;
	isNight = false;
	//Create player, and the one npc currently in the game.
	Player* player = new Player;
	Busker* busker = new Busker;
	GateKeeper* gateKeeper = new GateKeeper;

	std::cout << "You walk through the tall wooden gates.\n";
	Sleep(1500);
	std::cout << "The forest lies behind you, nothing but trees and empty sky.";
	Sleep(3500);
	system("CLS");
	std::cout << "Gatekeeper: So you came. \nMost everyone passes through here sometime.";
	Sleep(3500);
	system("CLS");
	std::cout << "Gatekeeper: What you do now is up to you. \nYou can take a place in the town,";
	Sleep(3000);
	std::cout << " or venture back into the forest.";
	Sleep(3500);
	system("CLS");
	std::cout << "Gatekeeper: You can even explore the binary trees, see what you find.\n";
	Sleep(3500);
	std::cout << "Just be careful of the higher branches.";
	Sleep(3500);
	system("CLS");
	std::cout << "Regardless, you will choose one day, but until then feel free to make use of the town.";
	Sleep(4000);
	system("CLS");

	while (playing) {
		if (!inHub) {
			Dungeon(inHub, player, gateKeeper);
		}
		else {
			Hub(inHub, player, busker, gateKeeper);
		}
	}
	
}

void Game::Hub(bool& inHub, Player* player, Busker* busker, GateKeeper* gateKeeper) {
	Render(busker, player);
	std::cout << "Money: " << player->GetMoney() << "\tLevel: " << player->GetLevel() << std::endl;
	player->HubUpdate(isNight, inHub);
	//Check for player position against set locations
	if (player->GetPosition().iX == 5 && player->GetPosition().iY == 0)
		player->Home(isNight);
	while (player->GetPosition().iX == busker->GetPosition().iX && player->GetPosition().iY == busker->GetPosition().iY && !isNight) {
		Render(busker, player);
		std::cout << busker->GetDescription();
		player->Tip(busker);
	}
	while (player->GetPosition().iX == 4 && player->GetPosition().iY == 4) {
		Render(busker, player);
		player->Shop(isNight);
	}
	if (player->GetPosition().iX == gateKeeper->GetPosition().iX && player->GetPosition().iY == gateKeeper->GetPosition().iY) {
		std::cout << gateKeeper->GetDescription();
		gateKeeper->Talk(isNight, inHub, player);
	}
}

void Game::Render(Friendlies* busker, Player* player) {
	
	system("CLS");
	if (!isNight)
		std::cout << "Day\n";
	else
		std::cout << "Night\n";
	bool emptySpace = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			emptySpace = true;
			//Place Player
			if (player->GetPosition().iX == i &&
				player->GetPosition().iY == j) {
				emptySpace = false;
				std::cout << "P";
			}
			//Place Busker
			if (busker->GetPosition().iX == i &&
				busker->GetPosition().iY == j) {
				emptySpace = false;
				std::cout << "B";
			}
			//Place Store
			if (i == 4 && j == 4) {
				emptySpace = false;
				std::cout << "S";
			}
			//Place Gate
			if (i == 0 && j == 5) {
				emptySpace = false;
				std::cout << "G";
			}
			//Place Home
			if (i == 5 && j == 0) {
				emptySpace = false;
				std::cout << "H";
			}
			if (emptySpace) {
				std::cout << "-";
			}
			std::cout << "   ";
		}
		std::cout << std::endl;
	}
	
}