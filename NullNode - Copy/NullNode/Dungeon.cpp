//November 10: created .cpp and tested navigation through a dungeon
//November 12: Added enemies
//November 13: Added fights between players and enemies.

#include "Game.h"

void Game::Dungeon(bool& inHub, Player* player, GateKeeper* gateKeeper) {
	Tree tree;
	tree.CreateTree(isNight);
	Node* playerPosition = tree.rootNode;
	bool dungeonState = true;

	while (!inHub) {
		system("CLS");
		player->DisplayStats();
		std::cout << std::endl;
		//Give player's text based directions
		std::cout << "You are " << playerPosition->getDepth() << " levels high.\n";
		std::cout << "There are branches to your";
		if (playerPosition->GetLeft() != NULL)
			std::cout << " left, ";
		if (playerPosition->GetRight() != NULL)
			std::cout << " right";
		if (playerPosition->GetPrevious() != NULL)
			std::cout << " back";
		std::cout << ".\n";
		//See if player is at the entrance. If so, allow them to return
		if (playerPosition->getDepth() == 0) {
			std::cout << "The entrance to the forest is directly behind you. (R)eturn\n";
		}
		//If an enemy is near, the player hears a noise.
		if (playerPosition->GetLeft() != nullptr) {
			if (playerPosition->GetLeft()->getRoom()->host != nullptr) {
				std::cout << "\nYou hear a noise to the left.\n";
			}
		}
		if (playerPosition->GetRight() != nullptr) {
			if (playerPosition->GetRight()->getRoom()->host != nullptr) {
				std::cout << "\nYou hear an noise to the right.\n";
			}
		}

		playerPosition = player->DungeonMove(playerPosition, inHub);
		if (playerPosition == NULL) {
			gateKeeper->ReturnToHub(player);
			inHub = true;
		}
		//Compares playerPosition node pointer to the current node's room
		//If there is an enemy, call battle function.
		if (playerPosition != NULL && playerPosition->getRoom()->host != NULL) {
			std::cout << "A " << playerPosition->getRoom()->host->GetName() 
				<< " rushes to attack!" << std::endl;
			Sleep(2500);
			//Call Battle, fight.
			Battle(playerPosition->getRoom()->host, player);
			playerPosition->getRoom()->host = nullptr;
		}

		if (playerPosition != NULL && playerPosition->getRoom()->gateKeeperPiece) {
			std::cout << "On the ground lies a lost memory. A memento from another time and place.\n" <<
				"Gatekeeper piece obtained";
			player->gateKeeperPiece = true;
			playerPosition->getRoom()->gateKeeperPiece = false;
			Sleep(3000);
		}
	}
}

void Game::Battle(Character* foe, Player* player) {
	//add fighters to a list in order of their speed
	std::list<Character*> initiative;
	if (foe->GetStats().m_Agility < player->GetStats().m_Agility) {
		initiative.push_back(foe);
		initiative.push_back(player);
	}
	else {
		initiative.push_back(player);
		initiative.push_back(foe);
	}
	//Create pointers to both items on the list, and one to swap them
	//to change who is attacking this turn.
	std::list<Character*>::iterator first = initiative.begin();
	std::list<Character*>::iterator second = initiative.begin();
	second++;
	std::list<Character*>::iterator swapper;
	//Check to see if both combatants are alive
	while (foe->bAlive() && player->bAlive()) {	
		system("CLS");
		player->DisplayDungeonStats();
		std::cout << std::endl;
		foe->DisplayDungeonStats();
		std::cout << std::endl;
		//During the fight, swap the iterator positions and call the attack function
		swapper = first;
		first = second;
		second = swapper;
		//Call dungeon update on the characters.
		//The character first points to attacks the character second points to.
		(*first)->DungeonUpdate(*second, *first);
		Sleep(2500);
	}
	//if a fighter's health drops below zero,
	//the loop breaks.
	if (!foe->bAlive()) {
		//Delete the enemy if their health drops below zero
		delete foe;
		Sleep(2500);
	}
	else if (!player->bAlive()){
		//Boots player back to hub, calls Die() function in player.
		std::cout << "You have died.\n";
		Sleep(2500);
		inHub = true;
		player->Die();
	}
}
