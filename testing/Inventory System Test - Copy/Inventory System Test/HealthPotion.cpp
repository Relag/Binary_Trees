#include "HealthPotion.h"

HealthPotion::HealthPotion() {
	m_sDescription = "A red vial that contains with life.";
	m_iHealthReplenish = 10;
	m_sName = "Health Potion";
}

void HealthPotion::Effect() {
	std::cout << "\n You healed " << m_iHealthReplenish << " health.\n";
}

void HealthPotion::Use(std::map<Item*, int>& map) {
	if (map.find(this)->second > 0) {
		Effect();
		map.find(this)->second -= 1;
	}
	else {
		std::cout << "Your vial is empty.\n";
	}
}
