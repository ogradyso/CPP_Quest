#include "QuestCharacter.h"
#include "QuestLearner.h"
#include <string>


//default constructor:
QuestCharacter::QuestCharacter()
{}

QuestCharacter :: QuestCharacter(std::string characterName, std::string characterType)
	: characterName(characterName), characterType(characterType)
{}

//default constructor:
MainCharacter::MainCharacter()
{}

MainCharacter::MainCharacter(std::string characterName, std::string characterType)
	: QuestCharacter(characterName, characterType)
{
	learner = QuestLearner();
}

