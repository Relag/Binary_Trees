#include "Player.h"
//Novemeber 14 2019: Created .cpp file. Added Heal and Fireball magic.
//November 16, 2019: Fixed healing bug where the player would heal above maximum.
//November 20, 2019: fixed bug where an enemy killed by magic did not add to enemiesKilled.

void Player::MagicAttack(Character* enemy, Character* player) {
	DisplayMagic();
	char cInput = 0;
	//List the player options
	switch (cInput = _getch()) {
	case 'f':
		FireBall(enemy, player);
		break;
	case 'h':
		Heal(enemy, player);
		break;
	case'b':
		system("CLS");
		DungeonUpdate(enemy, player);
	default:
		MagicAttack(enemy, player);
	}
	
}

void Player::FireBall(Character* enemy, Character* self) {
	//Ensure there is an enemy and the player has magic points.
	if (enemy != NULL) {
		if (m_Stats.m_Magic > 0) {
			int damage = (rand() % m_Stats.m_MaxMagic) * 2 +
				rand() % m_Stats.m_Strength + m_Stats.m_MaxMagic;
			//Check it attack will kill enemy.
			if (enemy->GetStats().m_Health <= damage)
				m_EnemiesKilled++;
			enemy->GetHit(damage);
			m_Stats.m_Magic--;
		}
		else {
			std::cout << m_Name << " has no magic left.\n";
			DungeonUpdate(enemy, self);
		}
	}
	else
		std::cout << "There is no target.\n";
}

void Player::Heal(Character* enemy, Character* self) {
	//Check if player has magic points left.
	if (m_Stats.m_Magic > 0) {
		//Heal heals based on magic stat and level.
		int healing = rand() % m_Stats.m_MaxMagic +
			m_Stats.m_MaxMagic + m_Stats.m_Level;
		m_Stats.m_Health += healing;
		//Ensure health does not exceed maxHealth
		if (m_Stats.m_Health > m_Stats.m_MaxHealth)
			m_Stats.m_Health = m_Stats.m_MaxHealth;
		std::cout << "\n" << m_Name << " healed " << healing <<
			" points of damage.\n";
		m_Stats.m_Magic--;
	}
	else {
		//Boot player back to dungeonUpdate if they accidentally
		//try to use magic with no points.
		std::cout << m_Name << " has no magic left.\n";
		DungeonUpdate(enemy, self);
	}
}

void Player::DisplayMagic() {
	system("CLS");
	std::cout << "\n(H)eal\t(F)ireball\t(B)ack\n";
}