#pragma once
#include <string>
#include <iostream>
#include "QuestGame.h"
#include <filesystem>
#include <fstream>
#include <regex>
#include "tinyxml2.h"

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
		const char* lessonRoot = "IntroLessons";
		const char* lessonLevel = "Lesson1";
		int expGain;
		std::filesystem::path lessonFilepath = std::filesystem::current_path().string() + "\\QuestFiles\\IntroLessons.xml";
		int savedExperience = this->loadSavedGame();
		QuestLearner mainCharacter = QuestLearner(savedExperience);
		mainCharacter.getLessonInfo(lessonRoot, lessonLevel, lessonFilepath.string().c_str());
		expGain = StartLesson(mainCharacter);
		mainCharacter.setExp(expGain);
		std::cout << "You have " << savedExperience << " experience points!" << '\n';
		std::string continueChoice = inputVal("[C|S|E]", "Would you like to (C)ontinue with the next lesson, (S)ave your current progress, or (E)xit the game and return to the command line?\n", "You will need to enter either a C for Continue, an S for Save or an E for Exit.\n");

		switch (*continueChoice.begin()) {
		case 'C':
			expGain = StartLesson(mainCharacter);
			[[fallthrough]];
		case 'S':
			this->SaveGame(mainCharacter);
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

int QuestGame::StartLesson(QuestLearner learningCharacter) {
	std::cout << "Starting the next lesson..." << '\n';
	int expGained = learningCharacter.startNextLesson();
	std::cout << "You gained " << expGained << " experience points!" << '\n';
	return expGained;
}

void QuestGame::SaveGame(QuestLearner learningCharacter) {
	std::cout << "Saving your progress..." << '\n';
	bool saveComplete = learningCharacter.saveProgress(this->gameFilePath.string().c_str());

}

int QuestGame::loadSavedGame() {
	tinyxml2::XMLDocument xmlDoc;
	auto ptrGameFilePath = this->gameFilePath;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile(ptrGameFilePath.string().c_str());

	const char* gameFileRoot = "GameFile";
	const char* playerNode = "PlayerOne";
	tinyxml2::XMLNode* PlayersRoot = xmlDoc.FirstChildElement(gameFileRoot);

	tinyxml2::XMLElement* playerData = PlayersRoot->FirstChildElement(playerNode);
	const char* savedExperience = playerData->Attribute("CurrentExp");
	return std::stoi(savedExperience);
}

std::filesystem::path QuestGame::getGameFilePath() {
	return this->gameFilePath;
}

