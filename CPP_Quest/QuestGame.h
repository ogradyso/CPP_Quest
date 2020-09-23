#pragma once
#include <string>
#include <vector>
#include "QuestCharacter.h"
#include "QuestLearner.h"
#include "QuestDialogue.h"
#include <filesystem>


#ifndef QuestGame_H
#define QuestGame_H

class QuestGame {
	
private:
	std::filesystem::path gameFilePath;
public: 
	QuestGame(std::filesystem::path gameFilePath);
	QuestLessonPrompt nextLesson;
	void StartGame(void);
	void StartLesson();
	std::vector<QuestCharacter> advisorList;
	std::vector<QuestCharacter> allyList;
	std::vector<QuestCharacter> enemyList;
};

#endif