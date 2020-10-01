#include <string>
#include <iostream>
#include "QuestGame.h"
#include <filesystem>
#include <fstream>

QuestGame :: QuestGame(std::filesystem::path gameFilePath)
	: gameFilePath(gameFilePath), advisorList(), allyList(), enemyList()
{}

void QuestGame :: StartGame(void) {
	
	

}

void QuestGame::StartLesson() {
	
}

