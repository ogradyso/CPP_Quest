#include <iostream>
#include "QuestGame.h"


using namespace std;

void StartGame(void) {
	system("clear");
	string playerName;
	cout << "What is your name?" << '\n';
	cin >> playerName;
	cout << '\n';
	char learningClass;
	cout << "Which learning class would you like to choose?" << '\n';
	cout << "(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard" << '\n';
	cin >> learningClass;
	while (learningClass != 'L' && learningClass != 'S' && learningClass != 'E') {
		cout << "You must choose an upper case letter associated with the learning class you would like to pursue:" << '\n';
		cout << "(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard" << '\n';
		cin >> learningClass;
		cout << '\n';
	}
	char playerClass;
	cout << "Which player class would you like to choose?" << '\n';
	cout << "(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard" << '\n';
	cin >> playerClass;
	while (playerClass != 'L' && playerClass != 'S' && playerClass != 'E') {
		cout << "You must choose an upper case letter associated with the learning class you would like to pursue:" << '\n';
		cout << "(A)rcher; (K)night; (M)age" << '\n';
		cin >> playerClass;
		cout << '\n';
	}
	

	cout << '\n';
}

int main() {

	cout << "  QQ     UU  UU  EEEEEE    SS    TTTTTT  " << '\n';
	cout << "QQ  QQ   UU  UU  EE      SS  SS    TT    " << '\n';
	cout << "QQ  QQ   UU  UU  EEEEEE   SS       TT    " << '\n';
	cout << "QQ  QQ   UU  UU  EE         SS     TT    " << '\n';
	cout << "  QQ     UUUUUU  EE      SS  SS    TT    " << '\n';
	cout << "   QQQ    UUUU   EEEEEE    SS      TT    " << '\n' << '\n';
	cout << "You have chosen to embark on an epic journey!" << "\n\n";
	cout << "Would you like to (L)oad a saved Quest, (S)tart a new Quest, or (E)xit the game and return to the command line?" << '\n';

	char startChoice;
	cin >> startChoice;
	while (startChoice != 'L' && startChoice != 'S' && startChoice != 'E') {
		cout << "You will need to enter either an L for Load, an S for Start or an E for Exit." << '\n';
		cin >> startChoice;
		cout << '\n';
	}
	switch (startChoice) {
	case 'L':
		cout << "Okay, which game would you like to load?" << '\n';
		cout << "Feature broken at this time. Exiting." << '\n';
		break;
	case 'S':
		cout << "Very well, we shall prepare for our journey!" << '\n';
		StartGame();
		break;
	case 'E':
		cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
		return 1;
	default:
		return 1;
	}

}