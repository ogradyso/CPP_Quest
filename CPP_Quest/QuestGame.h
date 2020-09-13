#pragma once
#include <string>

#ifndef QuestGame_H
#define QuestGame_H

class QuestGame {
	
private:
	const std::string gameFilePath;
public: 
	QuestGame(const std::string gameFilePath);
};

#endif