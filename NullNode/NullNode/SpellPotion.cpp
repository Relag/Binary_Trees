#include "SpellPotion.h"
SpellPotion::SpellPotion() {
	m_Description = "A blue vial that contains magical energy.";
	m_MagicReplenish = 2;
	m_Name = "(S)pell Potion";
}

void SpellPotion::Use(Character* player) {
	player->ReplenishMagic(m_MagicReplenish);
}