// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
////Maybe have a queue witht he most agility at the front and least at the back. Pop off the front after Attack() is called then place on back? DONE: April 9 2020
    //Handle cleanup at the end. Check to see if fighter is alive before attacking and readding to list. DONE: April 10 2020
    //Should I have an enum like Friend or Foe? This determines who to target. Bool might suffice. DONE: April 10 2020
    //TODO:
    //Add randomization so fighters use their special moves. DONE FOR GOBLIN: April 11, 2020
    //Add ability to play as Hero 1
    //Create Act function in fighter. Keep turn logic inside classes. Pass in vector to keep turn order queue intact. 

#include <iostream>
#include <ctime>
#include "Hero.h"
#include "Goblin.h"
#include "Player.h"
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

    Player* player = new Player;
    Hero* hero2 = new Hero;
    Goblin* goblin1 = new Goblin;
    Goblin* goblin2 = new Goblin;
    srand(time(NULL));

    //Queue is primarily for turn order, Vector is for player and AI actions
    std::queue<Fighter*> qFighters;
    std::vector<Fighter*> vFighters;
    //Add all fighters to the vector
    vFighters.push_back(player);
    vFighters.push_back(hero2);
    vFighters.push_back(goblin1);
    vFighters.push_back(goblin2);

    hero2->setName("Hero2");
    goblin1->setName("Goblin1");
    goblin2->setName("Goblin2");

    std::cout << std::endl;
    //Sort the fighters according to agility using FighterSort function above.
    std::sort(vFighters.begin(), vFighters.end(), FighterSort);

    //Add fighters to the queue
    for (int i = 0; i < vFighters.size(); i++) {
        qFighters.push(vFighters[i]);
    }
    //Create a heroes and a villians vector for use in choosing who to fight.
    std::vector<Fighter*> vHeroes;
    vHeroes.push_back(player);
    vHeroes.push_back(hero2);

    std::vector<Fighter*> vVillians;
    vVillians.push_back(goblin1);
    vVillians.push_back(goblin2);

    int randNum;
    //Game continues until all combatants on one team have died.
    while (!vVillians.empty() && !vHeroes.empty()) {
        //Safety check to ensure next combatant is alive. 
        //First if is for villian actions, second is for hero actions
        if (qFighters.front()->IsAlive() && qFighters.front()->GetIsFoe()) {
            qFighters.front()->Act(vVillians, vHeroes);
            //Move fighter to the back of the queue
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
        else if (qFighters.front()->IsAlive()) {
            qFighters.front()->Act(vHeroes, vVillians);
            qFighters.push(qFighters.front());
            qFighters.pop();
        }
        //If fighter is dead delete them and remove their pointer from the list
        else {
            delete qFighters.front();
            qFighters.pop();
        }

        Sleep(1500);

        system("cls");

        //Repopulate vectors to remove dead fighters.
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


