
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>
#include <iostream>
#include "Character.h"
class Item
{
public:
	std::string GetDescription() { return m_Description; }
	virtual void Use(Character* player) = 0;
	std::string GetName() { return m_Name; }
	int GetRemaining() { return numberRemaining; }
protected:
	std::string m_Description;
	std::string m_Name;
	int numberRemaining;

};
#endif // !ITEM_H