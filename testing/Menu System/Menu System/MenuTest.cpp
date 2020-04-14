#include<iostream>
#include<vector>

//May create as a singleton later.
//Pass in pre-created iterator and have a separate switch statement to interpret the choice?
void Menu(std::vector<std::string> choices, std::string intro = "") {
	std::cout << std::endl << intro << std::endl << std::endl;
	std::vector<std::string>::iterator iter = choices.begin();
	for (int i = 0; i < choices.size(); i++) {
		if ((*iter) == choices[i]) {
			std::cout << "-->";
		}
		std::cout << "\t" << choices[i] << std::endl;
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





