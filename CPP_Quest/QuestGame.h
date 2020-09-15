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
public: 
	QuestGame(std::filesystem::path gameFilePath);
	void StartGame(void);
	std::vector<QuestCharacter> advisorList;
	std::vector<QuestCharacter> allyList;
	std::vector<QuestCharacter> enemyList;
};

#endif