#include <string>
#include <iostream>
#include "QuestGame.h"
#include "GameLoader.h"
#include <filesystem>
#include <fstream>
#include <regex>

QuestGame::QuestGame()
{};

QuestGame::QuestGame(GameLoader_H::GameLoader questLoader) : fileLoader(questLoader) {

};

void QuestGame::StartGame() {
	bool continueGame = true;
	int expGain;
	this->player = this->fileLoader.LoadGameFile();
	std::filesystem::path lessonFilepath = std::filesystem::current_path().string() + "/QuestFiles/" + this->player.getNextLessonUnit() + ".xml";
	this->player.getLessonInfo(this->player.getNextLessonUnit().c_str(), this->player.getNextLesson().c_str(), lessonFilepath.string().c_str());
	for (int i = 0; i <= 30; i++) {
		std::cout << '\n';
	}
	std::cout << "Welcome to ThistleWood! This is you training environment." << '\n';
	std::cout << "In order to prepare you for the journey ahead, we must" << '\n';
	std::cout << "first train you in the art of C++ Questing." << '\n\n';
	std::string journeyChoice = this->inputValidation("[T|J]", "If you are brave, you may choose to start your (J)ourney now, but we recommend you (T)rain first!\n", "You will need to enter either T for Train of J for Journey.");
	if (*journeyChoice.begin() == 'T') {
		expGain = this->StartLesson();
		if (expGain >= this->player.getNextLessonTargetExp()) {
			this->player.setNextLesson();
		}
		this->player.setExp(expGain);
		std::string continueChoice = this->inputValidation("[C|S|E]", "Would you like to (C)ontinue with the next lesson, (S)ave your current progress, or (E)xit the game and return to the command line?\n", "You will need to enter either a C for Continue, an S for Save or an E for Exit.\n");;
		while (continueGame) {
			switch (*continueChoice.begin()) {
			case 'C':
				lessonFilepath = std::filesystem::current_path().string() + "/QuestFiles/" + this->player.getNextLessonUnit() + ".xml";
				this->player.getLessonInfo(this->player.getNextLessonUnit().c_str(), this->player.getNextLesson().c_str(), lessonFilepath.string().c_str());
				expGain = this->StartLesson();
				if (expGain >= this->player.getNextLessonTargetExp()) {
					this->player.setNextLesson();
				}
				[[fallthrough]];
			case 'S':
				this->SaveGame();
				continueChoice = this->inputValidation("[C|S|E]", "Would you like to (C)ontinue with the next lesson, (S)ave your current progress, or (E)xit the game and return to the command line?\n", "You will need to enter either a C for Continue, an S for Save or an E for Exit.\n");
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
	else {
		std::cout << "Feature broken at this time.";
	}
};

int QuestGame::StartLesson() {
	std::cout << this->player.getName() + " you are about to embark on your next lesson!" << '\n';
	int expGained = this->player.startNextLesson();
	std::cout << "You gained " << expGained << " experience points!" << '\n';
	return expGained;
};

void QuestGame::SaveGame() {
	std::cout << "Saving your progress..." << '\n';
	bool saveComplete = this->fileLoader.saveProgress(this->player.getExp());

};

void QuestGame::setGameFilePath(std::filesystem::path gameFilePathInput) {
	this->gameFilePath = gameFilePathInput;
};

std::filesystem::path QuestGame::getGameFilePath() {
	return this->gameFilePath;
};

std::string QuestGame::inputValidation(std::string strPatternOfOptions, std::string promptToUser, std::string followUpPrompt) {
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
};

