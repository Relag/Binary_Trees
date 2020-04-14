#include<iostream>
#include<vector>
#include<stdio.h>
#include<Windows.h>

//May create as a singleton later.
//Pass in pre-created iterator and have a separate switch statement to interpret the choice?
void Menu(std::vector<std::string> choices, std::string intro = "") {
	std::cout << intro;
	std::vector<std::string>::iterator iter = choices.begin();
	int cDirection = 0;
	while (!GetKeyState(VK_RETURN)){
		for (int i = 0; i < choices.size(); i++) {
			if ((*iter) == choices[i]) {
				std::cout << "-->";
			}
			std::cout << "\t" << choices[i] << std::endl;
		}
		Sleep(50);
		if (GetKeyState(VK_DOWN) & 0x8000 && iter != choices.end() - 1)
			iter++;
		else if (GetKeyState(VK_UP) & 0x8000 && iter != choices.begin())
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

	system("PAUSE");

	return 0;
}





