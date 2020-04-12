// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include "Hero.h"
#include "Goblin.h"
#include <queue>
#include <vector>
#include <Windows.h>

bool FighterSort(Fighter* a, Fighter* b) {
    return a->GetStats().m_Agility > b->GetStats().m_Agility;
}

int main()
{
    //Maybe have a queue witht he most agility at the front and least at the back. Pop off the front after Attack() is called then place on back? DONE: April 9 2020
    //Handle cleanup at the end. Check to see if fighter is alive before attacking and readding to list. DONE: April 10 2020
    //Should I have an enum like Friend or Foe? This determines who to target. Bool might suffice. DONE: April 10 2020
    //TODO:
    //Add randomization so fighters use their special moves. DONE FOR GOBLIN: April 11, 2020
    //Add ability to play as Hero 1
    //Create Act function in fighter. Keep turn logic inside classes. Pass in vector to keep turn order queue intact. 

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

    std::vector<Fighter*> vHeroes;
    vHeroes.push_back(hero1);
    vHeroes.push_back(hero2);

    std::vector<Fighter*> vVillians;
    vVillians.push_back(goblin1);
    vVillians.push_back(goblin2);

    int randNum;

    while (!vVillians.empty() && !vHeroes.empty()) {
       

        if (qFighters.front()->IsAlive() && qFighters.front()->GetIsFoe()) {
            qFighters.front()->Act(vVillians, vHeroes);
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
        else if (qFighters.front()->IsAlive()) {
            qFighters.front()->Act(vHeroes, vVillians);
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
        else {
            delete qFighters.front();
            qFighters.pop();
        }

        Sleep(1500);

        system("cls");

        vVillians.clear();
        vHeroes.clear();
        vFighters.clear();

        for (int i = 0; i < qFighters.size(); i++) {

            std::cout << qFighters.front()->GetName() << ": " << qFighters.front()->GetStats().m_Health 
                << "/" << qFighters.front()->GetStats().m_MaxHealth << std::endl;

            if (qFighters.front()->GetIsFoe())
                vVillians.push_back(qFighters.front());
            else
                vHeroes.push_back(qFighters.front());
            
            vFighters.push_back(qFighters.front());
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
    }
}


