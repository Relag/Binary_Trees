#include "HealthPotion.h"

HealthPotion::HealthPotion() {
	m_Description = "A red vial that contains life.";
	m_HealthReplenish = 10;
	m_Name = "(H)ealth Potion";
}

void HealthPotion::Use(Character* player) {
	//Pass a negative value to GetHit, to heal player.
	player->Heal(m_HealthReplenish);

}
