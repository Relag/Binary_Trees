// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Hero.h"
#include "Goblin.h"

int main()
{
    //Maybe have a queue witht he most agility at the front and least at the back. Pop off the front after Attack() is called then place on back?
    //Handle cleanup at the end. Check to see if fighter is alive before attacking and readding to list.
    //Should I have an enum like Friend or Foe? This determines who to target. Bool might suffice.
    Hero* hero1 = new Hero;
    Hero* hero2 = new Hero;
    Goblin* goblin1 = new Goblin;
    Goblin* goblin2 = new Goblin;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
