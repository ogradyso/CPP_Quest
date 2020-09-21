#include "QuestCharacter.h"
#include "QuestCharacter.h"
#include <string>

QuestCharacter :: QuestCharacter(std::string characterName, std::string characterType)
	: characterName(characterName), characterType(characterType)
{}

MainCharacter :: MainCharacter(std::string playerName, std::string learningClass, std::string playerClass, int learningLevel, int playerLevel, double playerAttack, double playerDefense, double playerMagAttack, double playerMagDefense, double playerCharisma, double playerLuck, long totalExperiencePoints, int experiencePoints)
	: QuestCharacter(playerName, "Main"), strLearningClass(learningClass), strPlayerClass(playerClass), learningLevel(learningLevel), playerLevel(playerLevel), playerAttack(playerAttack), playerDefense(playerDefense), playerMagAttack(playerMagAttack), playerMagDefense(playerMagDefense), playerCharisma(playerCharisma), playerLuck(playerLuck), totalExperiencePoints(totalExperiencePoints), experiencePoints(experiencePoints)
{}

