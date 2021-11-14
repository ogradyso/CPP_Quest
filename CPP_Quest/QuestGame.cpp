#pragma once
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
	while (continueGame) {
		const char* lessonRoot = "IntroLessons";
		const char* lessonLevel = "Lesson1";
		int expGain;
		std::filesystem::path lessonFilepath = std::filesystem::current_path().string() + "/QuestFiles/IntroLessons.xml";
		this->player = this->fileLoader.LoadGameFile();
		this->player.getLessonInfo(lessonRoot, lessonLevel, lessonFilepath.string().c_str());
		expGain = this->StartLesson();
		this->player.setExp(expGain);
		std::string continueChoice = this->inputValidation("[C|S|E]", "Would you like to (C)ontinue with the next lesson, (S)ave your current progress, or (E)xit the game and return to the command line?\n", "You will need to enter either a C for Continue, an S for Save or an E for Exit.\n");

		switch (*continueChoice.begin()) {
		case 'C':
			expGain = this->StartLesson();
			[[fallthrough]];
		case 'S':
			this->SaveGame();
			break;
		case 'E':
			std::cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
			continueGame = false;
			break;
		default:
			std::cout << "Something went wrong." << '\n';
		}
	}
};

int QuestGame::StartLesson() {
	std::cout << "Starting the next lesson..." << '\n';
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

