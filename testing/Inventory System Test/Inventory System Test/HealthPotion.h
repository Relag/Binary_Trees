#pragma once
#include "Item.h"
#include <iostream>
#include <map>
class HealthPotion : public Item
{
public:
	HealthPotion();

protected:
	int m_iHealthReplenish;
	void Effect() ;
	void Use(std::map<std::string, std::pair<Item*, int>>& map) ;
};

