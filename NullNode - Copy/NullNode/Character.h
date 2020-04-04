#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <Windows.h>

class Character {
protected:
	//Stats for all characters. Strength determines attack damage, speed determines turn priority,
	//magic determines # of spells left and damage of spells.
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

	
	
public:
	~Character();
	Stats GetStats() { return m_Stats; }
	void DisplayStats();
	void DisplayDungeonStats();
	std::string GetName() { return m_Name; }
	bool bNightTime;
	bool bAlive() { return m_Stats.m_Health > 0; }
	//For attacking an enemy
	void Attack(Character* target);
	//For taking damage
	void GetHit(int damage);
	void Heal(int heal);
	void ReplenishMagic(int amount);
	virtual void DungeonUpdate(Character* foe, Character* self) = 0;
	
};


#endif // !CHARACTER_H
