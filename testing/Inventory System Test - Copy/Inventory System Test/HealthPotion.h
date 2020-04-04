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
	void Effect() override;
	void Use(std::map<Item*, int>& map) override;
};

