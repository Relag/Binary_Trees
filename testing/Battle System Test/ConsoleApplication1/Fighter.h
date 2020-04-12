#pragma once
#include <iostream>
#include <string>
#include <vector>

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
	void Attack(std::vector<Fighter*> target);
	void GetHit(int damage);
	void DisplayStats();
	void setName(std::string name) { m_Name = name; }
	Stats GetStats() { return m_Stats; }
	bool IsAlive() { return m_Stats.m_Health > 0; }
	bool GetIsFoe() { return isFoe; }
	bool isEnraged();
	void PowerUp();
	virtual void Act(std::vector<Fighter*> Allies, std::vector<Fighter*> Enemies) = 0;

	~Fighter();
};

