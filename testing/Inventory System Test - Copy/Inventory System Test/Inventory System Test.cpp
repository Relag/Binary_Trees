// Inventory System Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//November 10, 2019: Gonna go with map for this one. First value Item*, second value int number of item.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "HealthPotion.h"
#include "MajorHealthPotion.h"
#include "Item.h"



bool CompareItem(Item* a, Item* b) {
	return a->GetName() == b->GetName();
}

void AddItem (std::map<Item*, int>& map, Item* item) {
	bool alreadyContains = false;
	std::map<Item*, int>::iterator it = map.begin();
	it = map.find(item);
		if (it != map.end()) 
			(*it).second++;
		else
			map.emplace(item, 1);;
	
		map.find(item)->second;
		
}



int main()
{
	std::map<Item*, int> MInventory;
	HealthPotion* healthPotion = new HealthPotion;
	HealthPotion* healthPotion2 = new HealthPotion;
	HealthPotion* healthPotion3 = new HealthPotion;
	MajorHealthPotion* majorHealthPotion = new MajorHealthPotion;
	AddItem(MInventory, healthPotion);
	AddItem(MInventory, healthPotion2);
	AddItem(MInventory, healthPotion3);

	if (*healthPotion == *healthPotion3)
		std::cout << "true";
	else
		std::cout << "false";


}



