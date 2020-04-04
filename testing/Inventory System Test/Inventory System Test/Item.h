#pragma once
#include <string>
#include <map>
class Item
{
public:
	std::string GetDescription() { return m_sDescription; }
	virtual void Effect() = 0;
	virtual void Use(std::map<std::string, std::pair<Item*, int>>& map) = 0;
	std::string GetName() { return m_sName; }
	int GetRemaining() { return numberRemaining; }
protected:
	std::string m_sDescription;
	std::string m_sName;
	int numberRemaining;
	
};

