#pragma once
#include "HealthPotion.h"

class MajorHealthPotion : public HealthPotion
	
{
public:
	MajorHealthPotion();

private:
	void Effect() override;
	void Use(std::map<std::string, std::pair<Item*, int>>& map);
};

