#pragma once
#include <string>
#include <iostream>
#include "QuestGame.h"
#include <filesystem>
#include <fstream>
#include <regex>

std::string inputVal(std::string strPatternOfOptions, std::string promptToUser, std::string followUpPrompt) {
	std::string userInput;
	std::regex patternOfOptions{ (strPatternOfOptions) };
	std::cout << promptToUser;
	std::cin >> userInput;
	while (true) {
		if (std::regex_match(userInput, patternOfOptions)) {
			return userInput;
		}
		else {
			std::cout << followUpPrompt;
			std::cin >> userInput;
		}
	}
}

QuestGame::QuestGame(std::filesystem::path gameFilePath)
	: gameFilePath(gameFilePath)
{}

void QuestGame :: StartGame(void) {
	bool continueGame = true;
	while (continueGame) {
		StartLesson();
		std::string continueChoice = inputVal("[C|S|E]", "Would you like to (C)ontinue with the next lesson, (S)ave your current progress, or (E)xit the game and return to the command line?\n", "You will need to enter either a C for Continue, an S for Save or an E for Exit.\n");

		switch (*continueChoice.begin()) {
		case 'C':
			StartLesson();
			break;
		case 'S':
			SaveGame();
			break;
		case 'E':
			std::cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
			continueGame = false;
			break;
		default:
			std::cout << "Something went wrong." << '\n';
		}

	}
	

}

void QuestGame::StartLesson() {
	std::cout << "Starting the next lesson..." << '\n';
}

void QuestGame::SaveGame() {
	std::cout << "Saving your progress..." << '\n';
}


