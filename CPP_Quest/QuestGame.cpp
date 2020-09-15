#include <string>
#include <iostream>
#include "QuestGame.h"
#include <filesystem>
#include <fstream>

QuestGame :: QuestGame(std::filesystem::path gameFilePath)
	: gameFilePath(gameFilePath), advisorList(), allyList(), enemyList()
{}

void QuestGame :: StartGame(void) {
	std::string line;
	std::ifstream gameFile;
	std::vector<std::string> segments;
	gameFile.open(gameFilePath);
	while (std::getline(gameFile, line, ',')) {
		std::cout << line << '\n';
	}

}

