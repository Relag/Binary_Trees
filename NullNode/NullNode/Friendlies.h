#pragma once
#include "Character.h"
class Friendlies :
	public Character
{
protected:
	struct Position
	{
		int iX;
		int iY;
	}m_Position;

	int m_Deaths;
	int m_Affection;
	std::string m_Name;
	std::string m_Description;
	
public:
	
	int GetDeaths() { return m_Deaths; }
	int GetAffection() { return m_Affection; }
	void AddAffection() { m_Affection++; }
	Position GetPosition() { return m_Position; }
	std::string GetDescription() { return m_Description; }
	std::string GetName() { return m_Name; }
};

