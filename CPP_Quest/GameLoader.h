#pragma once
#include <filesystem>
#include "QuestCharacter.h"


#ifndef GameLoader_H
#define GameLoader_H

class GameLoader {

private:
	std::filesystem::path gameFilePath;
public:
	GameLoader();
	GameLoader(std::filesystem::path currentGameFilePath);
	std::filesystem::path CreateNewGameFile(std::string, std::string, std::string);
	QuestCharacter_H::QuestCharacter LoadGameFile();
	//SaveGameFile();
	///LoadNextLesson();
};

#endif