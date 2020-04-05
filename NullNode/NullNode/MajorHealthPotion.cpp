#include "MajorHealthPotion.h"

MajorHealthPotion::MajorHealthPotion() {
	m_Description = "A red vial that teems with life.";
	m_HealthReplenish = 20;
	m_Name = "(M)ajor Health Potion";
}

void MajorHealthPotion::Use(Character* player) {
	HealthPotion::Use(player);
}
