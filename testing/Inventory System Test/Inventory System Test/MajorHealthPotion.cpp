#include "MajorHealthPotion.h"

MajorHealthPotion::MajorHealthPotion() {
	m_sDescription = "A red vial that teems with life.";
	m_iHealthReplenish = 20; 
	m_sName = "Major Health Potion";
}

 void MajorHealthPotion::Effect() {
	std::cout << "\n You healed " << m_iHealthReplenish << " health.\n";
}

 void MajorHealthPotion::Use(std::map<std::string, std::pair<Item*, int>>& map) {
	 
	 if (map.find(this->GetName())->second.second > 0) {
		 Effect();
		 map.find(this->GetName())->second.second -= 1;
	 }
	 else {
		 std::cout << "Your vial is empty.\n";
	 }
 }

 