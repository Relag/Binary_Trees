//November 2: Created class. Created stats and level system
//November 12: Added DungeonUpdate function for fighting.
//November 14: Added inventory. Added shop and busker integration.
//November 17: Added spells

#include "Player.h"
#include <memory>

Player::Player() {
	//Set all first level stats
	m_Stats.m_Level = 4;
	m_Stats.m_MaxHealth = 13;
	m_Stats.m_Health = m_Stats.m_MaxHealth;
	m_Stats.m_Agility = 4;
	m_Stats.m_Strength = 4;
	m_Stats.m_MaxMagic = 4;
	m_Stats.m_Magic = m_Stats.m_MaxMagic;
	m_Deaths = 0;
	//Initial position
	m_Position.iX = 5;
	m_Position.iY = 0;
	//Currencies
	m_EnemiesKilled = 0;
	m_Money = 3;
	m_Experience = 20;
	m_Name = "Player";
	InventoryCreate();
}

void Player::Attack(Character* target)
{
	//Damage does a semi-random amount based on strength.
	int damage = rand() % m_Stats.m_Strength + m_Stats.m_Strength;
	//Add to enemiesKilled if enemy dies.
	if (target->GetStats().m_Health <= damage)
		m_EnemiesKilled++;
	std::cout << m_Name << " attacks.\n";
	//Call enemies getHit function to deal damage
	target->GetHit(damage);
}

//For when player's health drops to 0 in a dungeon.
void Player::Die() {
	system("CLS");
	std::cout << "Gatekeeper: I see you've been killed. No payment for that I'm afraid."; 
	m_EnemiesKilled = 0;
	m_Deaths++;
	Sleep(2500);
}

//Dictates position on the hub map
void Player::HubUpdate(bool& isNight, bool& hubGameState) {
	int cDirection = 0;

	switch (cDirection = _getch()) {
	case 72:	//Up Arrow
		if (m_Position.iX > 0)
			m_Position.iX--;
		break;
	case 80:	//Down Arrow
		if (m_Position.iX < 8)
			m_Position.iX++;
		break;
	case 75:	//Left Arrow
		if (m_Position.iY > 0)
			m_Position.iY--;
		break;
	case 77:	//Right Arrow
		if (m_Position.iY < 8)
			m_Position.iY++;
		break;
	} 
}
//Dictates position in the dungeon.
Node* Player::DungeonMove(Node* position, bool& HubGameState) {

	int cDirection = 0;

	switch (cDirection = _getch()) {
	case 80:	//Down Arrow
		if (position->GetPrevious() != NULL)
			return position->GetPrevious();
		else return position;
		break;
	case 75:	//Left Arrow
		if (position->GetLeft() != NULL)
			return position->GetLeft();
		else return position;
		break;
	case 77:	//Right Arrow
		if (position->GetRight() != NULL)
			return position->GetRight();
		else return position;
		break;
	case 114:	//'r'
		if (position->GetPrevious() == NULL) {
			HubGameState = true;
			return NULL;
		}
	case 105:	// 'i'
		OpenInventory(NULL, this);

	default:
		return position;
	}

}
//Gives the player a menu driven choice in battle.
void Player::DungeonUpdate(Character* enemy, Character* player) {
	std::cout << "(A)ttack\t(M)agic\t(I)nventory\n";
	
	char cInput = 0;
	switch (cInput = _getch()) {
	case 'a':
		Attack(enemy);
		break;
	case 'm':
		MagicAttack(enemy, player);
		break;
	case 'i':
		OpenInventory(enemy, player);
		break;
	default:
		DungeonUpdate(enemy, player);
	}
}
//Checks if player has enough money to buy an object.
bool Player::SpendMoney(int cost) {
	if (cost > m_Money) {
		std::cout << "\nNot enough money.\n";
		Sleep(2500);
		return false;
	}
	else {
		m_Money -= cost;
		return true;
	}
}
//If the player tips the busker enough times, they can gain experience points.
void Player::Tip(Friendlies* npc) {
	int cDirection = 0;
	std::cout << "\n(T)ip the busker?\n";
	switch (cDirection = _getch()) {
	case 72:	//Up Arrow
		if (m_Position.iX > 0)
			m_Position.iX--;
		break;
	case 80:	//Down Arrow
		if (m_Position.iX < 8)
			m_Position.iX++;
		break;
	case 75:	//Left Arrow
		if (m_Position.iY > 0)
			m_Position.iY--;
		break;
	case 77:	//Right Arrow
		if (m_Position.iY < 8)
			m_Position.iY++;
		break;
	case 116:	//'t'
		if (SpendMoney(1)) {
			npc->AddAffection();
			std::cout << "\nThe Busker smiles at you.";
			if (npc->GetAffection() > 20)
				m_Experience++;
			if (m_Experience > 8 * m_Stats.m_Level)
				LevelUp();
			Sleep(2500);
		}
	}	
}

void Player::Shop(bool& isNight) {
	int cDirection = 0;
	InventoryDisplay();
	std::cout << "What would you like to buy?";
	//Empty pointers that get Items.
	HealthPotion* healthPotion;
	SpellPotion* spellPotion;
	MajorHealthPotion* majorHealthPotion;
	
	//Player input to buy or move from store.
	switch (cDirection = _getch()) {
	case 72:	//Up Arrow
		if (m_Position.iX > 0)
			m_Position.iX--;
		break;
	case 80:	//Down Arrow
		if (m_Position.iX < 8)
			m_Position.iX++;
		break;
	case 75:	//Left Arrow
		if (m_Position.iY > 0)
			m_Position.iY--;
		break;
	case 77:	//Right Arrow
		if (m_Position.iY < 8)
			m_Position.iY++;
		break;
	case 104:
		if (SpendMoney(1)) {
			healthPotion = new HealthPotion;
			Additem(healthPotion);
		}
		break;
	case 109:
		if (SpendMoney(2)) {
			majorHealthPotion = new MajorHealthPotion;
			Additem(majorHealthPotion);
		}
		break;
	case 115:
		if (SpendMoney(1)) {
			SpellPotion* spellPotion = new SpellPotion;
			Additem(spellPotion);
		}
		break;
	}
}
//Called when the player has current level*5 experience
//Player levels maxhealth, plus one other stat of their choice.
void Player::LevelUp() {
	m_Stats.m_MaxHealth++;
	m_Stats.m_Level++;
	DisplayStats();
	std::cout << "\nWhat stat would you like to level?\n";
	std::cout << "(S)trength, (A)gility, (H)ealth, (M)agic\n";
	char cInput = 0;
	switch (cInput = _getch()) {
	case 'h':
		m_Stats.m_MaxHealth++;
		break;
	case 'm':
		m_Stats.m_MaxMagic++;
		break;
	case 's':
		m_Stats.m_Strength++;
		break;
	case 'a':
		m_Stats.m_Agility++;
		break;
	default:
		//If the player enters an invalid input
		//clear screen, make them do it again.
		system("CLS");
		m_Stats.m_MaxHealth--;
		m_Stats.m_Level--;
		LevelUp();
	}
	m_Experience = 0;
}
//The gate that allows players to go into the dungeon.
//Must be > level 5 to do so at night.
void Player::Gate(bool& isNight, bool& hubGameState) {
	int cDirection = 0;

	switch (cDirection = _getch()) {
	case 72:	//Up Arrow
		if (m_Position.iX > 0)
			m_Position.iX--;
		break;
	case 80:	//Down Arrow
		if (m_Position.iX < 8)
			m_Position.iX++;
		break;
	case 75:	//Left Arrow
		if (m_Position.iY > 0)
			m_Position.iY--;
		break;
	case 77:	//Right Arrow
		if (m_Position.iY < 8)
			m_Position.iY++;
		break;
	case 103:	//g
		if (!isNight || m_Stats.m_Level > 4)
			hubGameState = false;
	}
}
//Home replenishes player's health and magic.
void Player::Home(bool& isNight) {
	int cDirection = 0;
	DisplayStats();
	std::cout << "You are home. Would you like to (R)est?";

	switch (cDirection = _getch()) {
	case 72:	//Up Arrow
		if (m_Position.iX > 0)
			m_Position.iX--;
		break;
	case 80:	//Down Arrow
		if (m_Position.iX < 8)
			m_Position.iX++;
		break;
	case 75:	//Left Arrow
		if (m_Position.iY > 0)
			m_Position.iY--;
		break;
	case 77:	//Right Arrow
		if (m_Position.iY < 8)
			m_Position.iY++;
		break;
	case 114:	//r
		isNight = !isNight;
		m_Stats.m_Health = m_Stats.m_MaxHealth;
		m_Stats.m_Magic = m_Stats.m_MaxMagic;
	}
}

