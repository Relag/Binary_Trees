#include "Player.h"
#include <iostream>
//November 12: Created Class for testing
//November 14: Integrated map
//November 16: Disbanded class, moved functionality to player
void Player::InventoryCreate() {
	//Initialize one of each item to contain in the map
	/*HealthPotion* healthPotion = new HealthPotion;
	InventoryMap.emplace(healthPotion->GetName(), std::make_pair(healthPotion, 1));
	MajorHealthPotion* majorHealthPotion = new MajorHealthPotion;
	InventoryMap.emplace(majorHealthPotion->GetName(), std::make_pair(majorHealthPotion, 0));
	SpellPotion* spellPotion = new SpellPotion;
	InventoryMap.emplace(spellPotion->GetName(), std::make_pair(spellPotion, 0));*/
}

void Player::Additem(Item* item) {
	
	std::map<Item*, int>::iterator it = InventoryMap.begin();
	//Move the iterator to item positon or end of the map.
	while (it != InventoryMap.end() && (*it).first->GetName() != item->GetName())
		it++;
	//If iterator is at end of map add the item as a new item, otherwise iterate the item number.
	if (it == InventoryMap.end())
		InventoryMap.emplace(item->Copy(), 1);
	else {
		(*it).second++;
	}
	delete item;
}

void Player::InventoryDisplay() {
	for (std::map<Item*, int>::iterator iter = 
		InventoryMap.begin(); iter != InventoryMap.end(); iter++) {
		std::cout << iter->first->GetName() << ": " << iter->second<< std::endl;
	}
}

int Player::AmountofItem(std::string name) {
	std::map<Item*, int>::iterator iter;
	iter = InventoryMap.begin();
	while (iter != InventoryMap.end() && (*iter).first->GetName() != name)
		iter++;
	if (iter == InventoryMap.end())
		return 0;
	else
		return (*iter).second;
}

void Player::UseItem(std::string itemName) {
	std::map<Item*, int>::iterator it = InventoryMap.begin();
	while (it != InventoryMap.end() && (*it).first->GetName() != itemName)
		it++;
	// Use item if present. Remove from map if it is the player's last item.
	if (it == InventoryMap.end())
		return;
	else if ((*it).second == 1) {
		(*it).first->Use(this);
		InventoryMap.erase(it);
	}
	else {
		(*it).first->Use(this);
		(*it).second--;
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