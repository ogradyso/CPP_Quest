#include <iostream>
#include "QuestGame.h"
#include "QuestCharacter.h"
#include "GameLoader.h"
#include <regex>
#include <filesystem>
#include <fstream>

bool checkForGameFile(std::string fileName) {
	std::string gameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + fileName + ".xml";
	std::filesystem::path testPath{gameFilePath};
	if (exists(testPath)) {
		return true;
	}
	else {
		return false;
	}
}

void StartGame(QuestGame currentGame) {
	std::string playerName;
	std::cout << "What is your name?" << '\n';
	std::cin >> playerName;
	std::cout << '\n';
	std::string learningClass = currentGame.inputValidation("[H|A|L|N|W]", "Which learning class would you like to choose? \n(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard\n", "You must choose an upper case letter associated with a learning class:\n(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard\n");
	
	if (learningClass == "H") {
		learningClass = "Hobbyist";
	}
	else if (learningClass == "A") {
		learningClass = "Application developer";
	}
	else if (learningClass == "L") {
		learningClass = "Library developer";
	}
	else if (learningClass == "N") {
		learningClass = "Network developer";
	}
	else if (learningClass == "W") {
		learningClass = "Wizard";
	}
	std::string playerClass = currentGame.inputValidation("[A|K|M]", "Which player class would you like to choose? \n(A)rcher; (K)night; (M)age\n", "You must choose an upper case letter associated with a player class:\n(A)rcher; (K)night; (M)age\n");
	
	if (playerClass == "A") {
		playerClass = "Archer";
	}
	else if (playerClass == "K") {
		playerClass = "Knight";
	}
	else if (playerClass == "M") {
		playerClass = "Mage";
	}

	if (!checkForGameFile(playerName)) {
		std::filesystem::path gameFilePath = currentGame.fileLoader.CreateNewGameFile(playerName, learningClass, playerClass);
		currentGame.fileLoader.setGameFilePath(gameFilePath);
		currentGame.StartGame();
	}
	else {
		std::cout << "It looks like a game file with this name already exists.\n";
		std::string userPromptLoadGame = currentGame.inputValidation("[Y|N]", "Would you like to load the game : " + playerName + " ? \n", "You have to choose either Y for Yes or N for No.");
		if (*userPromptLoadGame.begin() = 'Y') {
			std::string strGameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + playerName + ".xml";
			std::filesystem::path gameFilePath{ strGameFilePath };
			currentGame.fileLoader.setGameFilePath(gameFilePath);
			currentGame.StartGame();
		}
		else {
			std::cout << "Okay, exiting the game.";
		}
	}
	std::cout << '\n';
}

int main() {
	GameLoader questLoader = GameLoader();
	QuestGame currentGame = QuestGame(questLoader);
	std::cout << "  QQ     UU  UU  EEEEEE    SS    TTTTTT  " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE      SS  SS    TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EEEEEE   SS       TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE         SS     TT    " << '\n';
	std::cout << "  QQ     UUUUUU  EE      SS  SS    TT    " << '\n';
	std::cout << "   QQQ    UUUU   EEEEEE    SS      TT    " << '\n' << '\n';
	std::cout << "You have chosen to embark on an epic journey!" << "\n\n";
	std::string startChoice = currentGame.inputValidation("[L|S|E]", "Would you like to (L)oad a saved Quest, (S)tart a new Quest, or (E)xit the game and return to the command line?\n", "You will need to enter either an L for Load, an S for Start or an E for Exit.\n");

	switch (*startChoice.begin()) {
	case 'L':
		std::cout << "Okay, which game would you like to load?" << '\n';
		std::cout << "Feature broken at this time. Exiting." << '\n';
		break;
	case 'S':
		std::cout << "Very well, we shall prepare for our journey!" << '\n';
		for (int i = 0; i <= 30;i++) {
			std::cout << '\n';
		}
		StartGame(currentGame);
		break;
	case 'E':
		std::cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
		return 1;
	default:
		return 1;
	}

}