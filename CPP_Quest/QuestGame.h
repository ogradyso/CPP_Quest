#pragma once
#include <string>
#include <vector>
#include "QuestCharacter.h"
#include <filesystem>


#ifndef QuestGame_H
#define QuestGame_H

class QuestGame {
	
private:
	std::filesystem::path gameFilePath;
	MainCharacter player;
public: 
	QuestGame();
	void StartGame(void);
	int StartLesson(QuestLearner);
	void SaveGame(QuestLearner);
	int loadSavedGame();
	std::filesystem::path getGameFilePath();
	std::string inputValidation(std::string, std::string, std::string);
	void setGameFilePath(std::filesystem::path gameFilePath);
};

#endif