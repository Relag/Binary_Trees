#pragma once
#include "Item.h"
class SpellPotion :
	public Item
{
public:
	SpellPotion();
	void Use(Character* player);
	int m_MagicReplenish;
};

