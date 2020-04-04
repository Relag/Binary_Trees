#pragma once
#include <string>
#include <map>
class Item
{
public:
	std::string GetDescription() { return m_sDescription; }
	virtual void Effect() = 0;
	std::string GetName() { return m_sName; }
	bool operator==(Item& pickUp);
protected:
	std::string m_sDescription;
	std::string m_sName;
	
	

};

