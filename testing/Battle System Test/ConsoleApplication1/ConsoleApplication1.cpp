// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Hero.h"
#include "Goblin.h"
#include <queue>
#include <vector>

bool FighterSort(Fighter* a, Fighter* b) {
    return a->GetStats().m_Agility < b->GetStats().m_Agility;
}

int main()
{
    //Maybe have a queue witht he most agility at the front and least at the back. Pop off the front after Attack() is called then place on back?
    //Handle cleanup at the end. Check to see if fighter is alive before attacking and readding to list.
    //Should I have an enum like Friend or Foe? This determines who to target. Bool might suffice.
    Hero* hero1 = new Hero;
    Hero* hero2 = new Hero;
    Goblin* goblin1 = new Goblin;
    Goblin* goblin2 = new Goblin;
    srand(time(NULL));

    std::queue<Fighter*> qFighters;
    std::vector<Fighter*> vFighters;

    vFighters.push_back(hero1);
    vFighters.push_back(hero2);
    vFighters.push_back(goblin1);
    vFighters.push_back(goblin2);

    hero1->setName("Hero1");
    hero2->setName("Hero2");
    goblin1->setName("Goblin1");
    goblin2->setName("Goblin2");

    for (std::vector<Fighter*>::iterator iter = vFighters.begin(); iter != vFighters.end(); iter++) {
        std::cout << (*iter)->GetName() << ": " << (*iter)->GetStats().m_Agility << std::endl;
    }

    std::cout << std::endl;

    std::sort(vFighters.begin(), vFighters.end(), FighterSort);

    for (std::vector<Fighter*>::iterator iter = vFighters.begin(); iter != vFighters.end(); iter++) {
        std::cout << (*iter)->GetName() << ": " << (*iter)->GetStats().m_Agility << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < vFighters.size(); i++) {
        qFighters.push(vFighters[i]);
    }

    for (int i = 0; i < 8; i++) {
        std::cout << qFighters.front()->GetName() << ": " << qFighters.front()->GetStats().m_Agility << std::endl;
        qFighters.push(qFighters.front());
        qFighters.pop();
    }
    std::cout << std::endl;

    std::vector<Hero*> vHeroes;
    vHeroes.push_back(hero1);
    vHeroes.push_back(hero2);

    std::vector<Goblin*> vVillians;
    vVillians.push_back(goblin1);
    vVillians.push_back(goblin2);

    while ((vVillians[0]->IsAlive() && vVillians[1]->IsAlive())
        && vHeroes[0]->IsAlive() && vHeroes[1]->IsAlive()) {
        if (qFighters.front()->IsAlive() && qFighters.front()->GetIsFoe()) {
            qFighters.front()->Attack(vHeroes[rand() % vHeroes.size()]);
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
        else if (qFighters.front()->IsAlive()) {
            qFighters.front()->Attack(vVillians[rand() % vVillians.size()]);
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
    }
}


