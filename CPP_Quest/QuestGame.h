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
	QuestGame(std::filesystem::path gameFilePath);
	void StartGame(void);
	int StartLesson(QuestLearner);
	void SaveGame(QuestLearner);
	int loadSavedGame();
	std::filesystem::path getGameFilePath();
};

#endif