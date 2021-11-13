#pragma once
#include <string>
#include <vector>
#include "QuestCharacter.h"
#include "GameLoader.h"
#include <filesystem>


#ifndef QuestGame_H
#define QuestGame_H

class QuestGame {
	
private:
	std::filesystem::path gameFilePath;
	QuestCharacter player;
public: 
	QuestGame();
	QuestGame(GameLoader);
	GameLoader_H::GameLoader fileLoader;
	void StartGame(void);
	int StartLesson();
	void SaveGame();
	void setGameFilePath(std::filesystem::path);
	//int loadSavedGame();
	std::filesystem::path getGameFilePath();
	std::string inputValidation(std::string, std::string, std::string);
};

#endif