#pragma once
#include "HealthPotion.h"

class MajorHealthPotion : public HealthPotion
	
{
public:
	MajorHealthPotion();

private:
	void Effect() override;
	void Use(std::map<Item*, int> map);
};

