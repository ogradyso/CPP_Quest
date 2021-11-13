#include "tinyxml2.h"
#include "GameLoader.h"
#include "QuestCharacter.h"
#include <filesystem>
#include <vector>
#include <string>

GameLoader::GameLoader() 
{
	this->gameFilePath = std::filesystem::current_path();
};

GameLoader::GameLoader(std::filesystem::path gameFilePath) : gameFilePath(gameFilePath) {

};

void GameLoader::setGameFilePath(std::filesystem::path newGameFilePath) {
	this->gameFilePath = newGameFilePath;
}

QuestCharacter_H::QuestCharacter GameLoader::LoadGameFile() {
	tinyxml2::XMLDocument xmlDoc;
	std::filesystem::path ptrGameFilePath = this->gameFilePath;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile(ptrGameFilePath.string().c_str());

	const char* gameFileRoot = "GameFile";
	const char* playerNode = "PlayerOne";
	tinyxml2::XMLNode* PlayersRoot = xmlDoc.FirstChildElement(gameFileRoot);

	tinyxml2::XMLElement* playerData = PlayersRoot->FirstChildElement(playerNode);
	const char* savedExperience = playerData->Attribute("CurrentExp");

	QuestCharacter mainCharacter = QuestCharacter(std::stoi(savedExperience));

	return mainCharacter;
};

std::filesystem::path GameLoader::CreateNewGameFile(std::string playerName, std::string learningClass, std::string characterClass) {
	const char* initExp = "0";
	std::string strGameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + playerName + ".xml";
	auto ptrGameFilePath = strGameFilePath.c_str();
	//create a document:
	tinyxml2::XMLDocument xmlDoc;
	//add an element (int)
	tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("GameFile");
	xmlDoc.InsertFirstChild(pRoot);
	tinyxml2::XMLElement* pPlayerElement = xmlDoc.NewElement("PlayerOne");
	pPlayerElement->SetAttribute("PlayerName", playerName.c_str());
	pPlayerElement->SetAttribute("LearningClass", learningClass.c_str());
	pPlayerElement->SetAttribute("CharacterClass", characterClass.c_str());
	pPlayerElement->SetAttribute("CurrentExp", initExp);

	pRoot->InsertEndChild(pPlayerElement);

	tinyxml2::XMLError eResult = xmlDoc.SaveFile(ptrGameFilePath);
	std::filesystem::path gameFilePath{ strGameFilePath };
	return gameFilePath;

};
