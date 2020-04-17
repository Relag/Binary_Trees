#include<iostream>
#include<vector>
#include<stdio.h>
#include<conio.h>
#include<Windows.h>

template <typename T>
//May create as a singleton later.
//Pass in pre-created iterator and have a separate switch statement to interpret the choice?
void Menu(std::vector<T> choices, std::string intro = "") {
	std::cout << intro;
	typename std::vector<T>::iterator iter = choices.begin();
	int cDirection = 0;
	while (cDirection != '\r'){
		cDirection = 0;
		for (int i = 0; i < choices.size(); i++) {
			if ((*iter) == choices[i]) {
				std::cout << "-->";
			}
			std::cout << "\t" << choices[i] << std::endl;
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

	std::vector<std::string> menu;

	menu.push_back("Hello");
	menu.push_back("Bonjour");
	menu.push_back("Goodbye");
	menu.push_back("Au Revoir");

	Menu(menu);

	std::vector<int> iMenu;

	iMenu.push_back(1);
	iMenu.push_back(2);
	iMenu.push_back(3);

	Menu(iMenu);

	system("PAUSE");

	return 0;
}





