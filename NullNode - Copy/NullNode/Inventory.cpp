#include "Player.h"
#include <iostream>
//November 12: Created Class for testing
//November 14: Integrated map
//November 16: Disbanded class, moved functionality to player
void Player::InventoryCreate() {
	//Initialize one of each item to contain in the map
	HealthPotion* healthPotion = new HealthPotion;
	InventoryMap.emplace(healthPotion->GetName(), std::make_pair(healthPotion, 1));
	MajorHealthPotion* majorHealthPotion = new MajorHealthPotion;
	InventoryMap.emplace(majorHealthPotion->GetName(), std::make_pair(majorHealthPotion, 0));
	SpellPotion* spellPotion = new SpellPotion;
	InventoryMap.emplace(spellPotion->GetName(), std::make_pair(spellPotion, 0));
}

void Player::Additem(std::string name) {
	InventoryMap.find(name)->second.second++;
}

void Player::InventoryDisplay() {
	for (std::map<std::string, std::pair<Item*, int>>::iterator iter = 
		InventoryMap.begin(); iter != InventoryMap.end(); iter++) {
		std::cout << iter->first << ": " << iter->second.second << std::endl;
	}
}

void Player::UseItem(std::string itemName) {
	if (InventoryMap.find(itemName)->second.second > 0) {
		InventoryMap.find(itemName)->second.first->Use(this);
		InventoryMap.find(itemName)->second.second -= 1;
	}
}

void Player::OpenInventory(Character* enemy, Character* player) {
	system("CLS");
	InventoryDisplay();
	std::cout << "(B)ack\n";
	char cInput = 0;

	switch (cInput = _getch()) {
	case 'h':
		UseItem("(H)ealth Potion");
		break;
	case 'm':
		UseItem("(M)ajor Health Potion");
		break;
	case 's':
		UseItem("(S)pell Potion");
		break;
	case 'b':
		if (enemy != NULL) {
			system("CLS");
			DungeonUpdate(enemy, player);
		}
		else
			break;
	default:
		OpenInventory(enemy, player);
	}
}