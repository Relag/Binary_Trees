//Player is split into 2 .cpp files: Player and MagicSpells.
//MagicSpells.cpp handles the definitions and usage of magic,
//while player.cpp handles the rest.
//There is also Inventory, which is a separate class, but
//handles all item related matters.

#ifndef PLAYER_H
#define PLAYER_H
#include "Friendlies.h"
#include "Enemies.h"
#include "Node.h"
#include <map>
#include <conio.h>
#include <iostream>
#include "Item.h"
#include "HealthPotion.h"
#include "MajorHealthPotion.h"
#include "SpellPotion.h"


class Player : public Character{
private:
	//For returning from tree
	struct Position
	{
		int iX;
		int iY;
	}m_Position;
	int m_EnemiesKilled;
	int m_Money;
	int m_Deaths;
	int m_Experience;
	

	std::map<std::string, std::pair<Item*, int>> InventoryMap;
public:
	Player();
	//Currencies
	int GetEnemiesKilled() { return m_EnemiesKilled; }
	void RemoveEnemiesKilled(){ m_EnemiesKilled = 0; }
	void AddEnemiesKilled() { m_EnemiesKilled++; }
	bool SpendMoney(int cost);
	int GetMoney() { return m_Money; }
	void AddMoney(int money) { m_Money += money; }
	void LevelUp();
	int GetLevel() { return m_Stats.m_Level; }
	void AddExperience(int exp) { m_Experience += exp; }
	int GetExperience() { return m_Experience; }
	bool gateKeeperPiece;
	//For Combat
	void Attack(Character* target);
	void MagicAttack(Character* enemy, Character* player);
	void DisplayMagic();
	void FireBall(Character* enemy, Character* self);
	void Heal(Character* enemy, Character* self);
	void DungeonUpdate(Character* enemy, Character* player);
	void Die();
	//Movement
	
	void HubUpdate(bool& isNight, bool& hubGameState);
	Node* DungeonMove(Node* position, bool &hubGameState);
	
	//Inventory
	void Additem(std::string name);
	void UseItem(std::string itemName);
	void InventoryDisplay();
	void InventoryCreate();
	void OpenInventory(Character* enemy, Character* player);
	//Talking to NPCs
	void Tip(Friendlies* npc);
	void Shop(bool& isNight);
	void Gate(bool& isNight, bool& hubGameState);
	void Home(bool& isNight);
	Position GetPosition() { return m_Position; }
};

#endif // !PLAYER_H