#include "QuestCharacter.h"
#include "QuestLearner.h"
#include <string>

QuestCharacter :: QuestCharacter(std::string characterName, std::string characterType)
	: characterName(characterName), characterType(characterType)
{}

//MainCharacter::MainCharacter(std::string characterName, std::string characterType)
//	: QuestCharacter(characterName, characterType)
//{
//	this->learnerClass = QuestLearner();
//}

