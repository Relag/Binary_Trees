#ifndef HEALTHPOTION_H

#define HEALTHPOTION_H


#include "Item.h"

class HealthPotion : public Item
{
public:
	HealthPotion();

	void Use(Character* player);
protected:
	int m_HealthReplenish;
};

#endif // !HEALTHPOTION_H