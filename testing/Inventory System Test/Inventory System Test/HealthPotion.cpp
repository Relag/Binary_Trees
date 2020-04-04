#include "HealthPotion.h"

HealthPotion::HealthPotion() {
	m_sDescription = "A red vial that contains with life.";
	m_iHealthReplenish = 10;
	m_sName = "Health Potion";
}

void HealthPotion::Effect() {
	std::cout << "\n You healed " << m_iHealthReplenish << " health.\n";
}

void HealthPotion::Use(std::map<std::string, std::pair<Item*, int>>& map) {
	if (map.find(this->GetName())->second.second > 0) {
		Effect();
		map.find(this->GetName())->second.second -= 1;
	}
	else {
		std::cout << "Your vial is empty.\n";
	}
}
