#include "tinyxml2.h"
#include "GameLoader.h"
#include "QuestCharacter.h"
#include <filesystem>
#include <vector>

GameLoader::GameLoader(std::filesystem::path gameFilePath) : gameFilePath(gameFilePath) {

};

std::vector<QuestCharacter> GameLoader::LoadGameFile() {
	tinyxml2::XMLDocument xmlDoc;
	auto ptrGameFilePath = this->gameFilePath;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile(ptrGameFilePath.string().c_str());

	const char* gameFileRoot = "GameFile";
	const char* playerNode = "PlayerOne";
	tinyxml2::XMLNode* PlayersRoot = xmlDoc.FirstChildElement(gameFileRoot);

	tinyxml2::XMLElement* playerData = PlayersRoot->FirstChildElement(playerNode);
	const char* savedExperience = playerData->Attribute("CurrentExp");

	QuestLearner mainCharacter = QuestLearner(savedExperience);



	return std::stoi(savedExperience);
};

void GameLoader::SaveGameFile() {


};

//LessonNode LoadNextLesson() {
//
//};