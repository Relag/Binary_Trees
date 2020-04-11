#pragma once
#include <iostream>
#include <string>

class Fighter
{
protected:
	struct Stats
	{
		int m_Strength;
		int m_Agility;
		int m_Magic;
		int m_MaxMagic;
		int m_Health;
		int m_MaxHealth;
		int m_Level;
	}m_Stats;

	std::string m_Name;
	bool isFoe;
	

public:
	std::string GetName() { return m_Name; }
	void Attack(Fighter* target);
	void GetHit(int damage);
	void DisplayStats();
	Stats GetStats() { return m_Stats; }
	bool IsAlive() { return m_Stats.m_Health > 0; }
	bool GetIsFoe() { return isFoe; }
};

