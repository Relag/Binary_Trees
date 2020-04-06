#pragma once
#include "HealthPotion.h"

class MajorHealthPotion : public HealthPotion

{
public:
	MajorHealthPotion();
	void Use(Character* player);
	Item* Copy();
private:


};


