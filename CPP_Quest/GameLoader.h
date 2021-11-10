#pragma once

#ifndef QuestGame_H
#define QuestGame_H

class GameLoader {

private:
	std::filesystem::path gameFilePath;
public:
	GameLoader(std::filesystem::path currentGameFilePath);
	std::vector<QuestCharacter> LoadGameFile();
	SaveGameFile();
	///LoadNextLesson();
};

#endif