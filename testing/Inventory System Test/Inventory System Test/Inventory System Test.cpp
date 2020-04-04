// Inventory System Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//November 10, 2019: Gonna go with map for this one. First value Item*, second value int number of item.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "HealthPotion.h"
#include "MajorHealthPotion.h"
#include "Item.h"

void Additem(Item* item, std::map<std::string, std::pair<Item*, int>>& map) {
	map.emplace(item->GetName(), std::make_pair(item, 0));
	map.find((*item).GetName())->second.second++;
}


int main()
{
	
	std::vector<Item*> vex;
	
	
	std::map<std::string, std::pair<Item*, int>> MInventory;
	HealthPotion* healthPotion = new HealthPotion;
	MajorHealthPotion* majorHealthPotion = new MajorHealthPotion;
	HealthPotion* Potion = new HealthPotion;

	HealthPotion Boop;
	//std::unique_ptr<HealthPotion> pBoop(&Boop);

	std::cout << std::endl << Boop.GetName() << std::endl;
	//std::cout << pBoop->GetName() << std::endl;
	
	//delete pBoop;

	//std::cout << Boop.GetName();


	/*
	Creating a vector/map of Items does not work, because the object is cast as an Item, which is a virtual object.
	This means that the object will try to call the fucntions from Item.
	HealthPotion healthPotion;
	vex.push_back(&healthPotion);
	*/

	//Therefore, I must push pointers to objects. However the objects will go out of scope whent the player
	//leaves the dungeon. So the objects must be created in the Player class when found.
	//Do I just create one of each object in the Inventory constructor and add their pointers to the map?

	Additem(healthPotion, MInventory);
	Additem(majorHealthPotion, MInventory);
	//vex[0]->GetName();
	
	
	std::map<std::string, std::pair<Item*, int>>::iterator mapIter;

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).second.first->GetName() << ": "  << (*mapIter).second.second << "\n";
	}
	Additem(Potion, MInventory);

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).second.first->GetName() << ": " << (*mapIter).second.second << "\n";
	}

	//delete healthPotion;

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).second.first->GetName() << ": " << (*mapIter).second.second << "\n";
	}


	




	/*std::map<std::string, std::pair<Item*, int>>::iterator mapIter;

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).second.first->GetName() << ": " << (*mapIter).second.second << "\n";
	}
	Additem(Potion, MInventory);

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).second.first->GetName() << ": " << (*mapIter).second.second << "\n";
	}*/





	/*for (int i = 0; i < 8; i++) {
		MInventory.find("Health Potion")->second.first->Use(MInventory);
		MInventory.find("Health Potion")->second->first->Use(MInventory);
		std::cout << MInventory.find()->first->GetName() << ": " << MInventory.find(healthPotion)->second << std::endl;
	}*/

	/*std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		MInventory.find(majorHealthPotion)->first->Use(MInventory);
		std::cout << MInventory.find(majorHealthPotion)->first->GetName() << ": " << MInventory.find(majorHealthPotion)->second << std::endl;
	}

	MInventory.emplace(healthPotion, 7);

	for (mapIter = MInventory.begin(); mapIter != MInventory.end(); mapIter++) {
		std::cout << (*mapIter).first->GetName() << ": " << (*mapIter).second << "\n";
	}*/

	return 0;
}

