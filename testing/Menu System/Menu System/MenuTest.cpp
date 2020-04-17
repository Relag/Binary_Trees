#include<iostream>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include "Test.h"

template <typename T>
//May create as a singleton later.
//Pass in pre-created iterator and have a separate switch statement to interpret the choice?
void Menu(std::vector<T*>& choices, std::string intro = "") {
	std::cout << intro;
	typename std::vector<T*>::iterator iter = choices.begin();
	int cDirection = 0;
	while (cDirection != '\r'){
		cDirection = 0;
		for (int i = 0; i < choices.size(); i++) {
			if ((**iter) == (*choices[i])) {
				std::cout << "-->";
			}
			std::cout << "\t" << (*choices[i]) << std::endl;
		}
		Sleep(50);
		cDirection = _getch();
			if (cDirection == 80 && iter != choices.end() - 1)
				iter++;
			else if (cDirection == 72 && iter != choices.begin())
				iter--;
		
		system("CLS");
		
	}
}

int main() {

	std::cout << "HI\n\n";

	std::vector<std::string*> menu;

	std::string string1 = "Hello";
	std::string string2 = "Bonjour";
	std::string string3 = "Goodbye";
	std::string string4 = "Au Revoir";

	std::string* p_string1 = new std::string;
	*p_string1 = "Hello";
	menu.push_back(p_string1);

	std::string* p_string2 = new std::string;
	*p_string2 = "Bonjour";
	menu.push_back(p_string2);

	std::string* p_string3 = new std::string;
	*p_string3 = "Goodbye";
	menu.push_back(p_string3);

	std::string* p_string4 = new std::string;
	*p_string4 = "Au Revoir";
	menu.push_back(p_string4);
	

	Menu(menu);

	std::vector<Test*> testMenu;

	Test* test1 = new Test;
	Test* test2 = new Test;
	Test* test3 = new Test;

	test1->name = "Kale";
	test2->name = "Carrot";
	test3->name = "Spinach";

	/*Test test1;
	Test test2;
	Test test3;*/

	/*test1.name = "Kale";
	test2.name = "Carrot";
	test3.name = "Spinach";*/

	testMenu.push_back(test1);
	testMenu.push_back(test2);
	testMenu.push_back(test3);

	Menu(testMenu);

	system("PAUSE");

	return 0;
}





