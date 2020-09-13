#include <iostream>
#include "QuestGame.h"
#include <regex>

void StartGame(void) {
	system("clear");
	std::string playerName;
	std::cout << "What is your name?" << '\n';
	std::cin >> playerName;
	std::cout << '\n';
	char learningClass;
	std::cout << "Which learning class would you like to choose?" << '\n';
	std::cout << "(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard" << '\n';
	std::cin >> learningClass;
	std::regex strToMatch{ ("[H|A|L|N|W]") };
	std::string s(1, learningClass);
	while (true) {
		if (std::regex_match(s, strToMatch)) {
			break;
		}
		else {
			std::cout << "You must choose an upper case letter associated with the learning class you would like to pursue:" << '\n';
			std::cout << "(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard" << '\n';
			std::cin >> learningClass;
			std::cout << '\n';
		}
	}
	char playerClass;
	std::cout << "Which player class would you like to choose?" << '\n';
	std::cout << "(A)rcher; (K)night; (M)age" << '\n';
	std::cin >> playerClass;
	strToMatch = ("[A|K|M]") ;
	std::string s1(1, learningClass);
	while (true) {
		if (regex_match(s, strToMatch)) {
			break;
		}
		else {
			std::cout << "You must choose an upper case letter associated with the player class you would like to pursue:" << '\n';
			std::cout << "(A)rcher; (K)night; (M)age" << '\n';
			std::cin >> learningClass;
			std::cout << '\n';
		}
	}
	

	std::cout << '\n';
}

int main() {
	std::cout << "  QQ     UU  UU  EEEEEE    SS    TTTTTT  " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE      SS  SS    TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EEEEEE   SS       TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE         SS     TT    " << '\n';
	std::cout << "  QQ     UUUUUU  EE      SS  SS    TT    " << '\n';
	std::cout << "   QQQ    UUUU   EEEEEE    SS      TT    " << '\n' << '\n';
	std::cout << "You have chosen to embark on an epic journey!" << "\n\n";
	std::cout << "Would you like to (L)oad a saved Quest, (S)tart a new Quest, or (E)xit the game and return to the command line?" << '\n';

	char startChoice;
	std::cin >> startChoice;
	std::regex strToMatch("[L|S|E]");
	std::string s(1, startChoice);
	while (true) {
		if (std::regex_match(s, strToMatch)) {
			break;
		}
		else {
			std::cout << "You will need to enter either an L for Load, an S for Start or an E for Exit." << '\n';
			std::cin >> startChoice;
			std::cout << '\n';
		}
	}
	switch (startChoice) {
	case 'L':
		std::cout << "Okay, which game would you like to load?" << '\n';
		std::cout << "Feature broken at this time. Exiting." << '\n';
		break;
	case 'S':
		std::cout << "Very well, we shall prepare for our journey!" << '\n';
		StartGame();
		break;
	case 'E':
		std::cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
		return 1;
	default:
		return 1;
	}

}