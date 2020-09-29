#pragma once
#include <string>


#ifndef QuestCharacter_H
#define QuestCharacter_H

class QuestCharacter {

protected:
	std::string characterName;
	std::string characterType;
public:
	QuestCharacter(std::string characterName, std::string characterType);
};

class MainCharacter : QuestCharacter {
private :
	QuestLearner learnerClass;
	/*int experiencePoints;
	long totalExperiencePoints;
	std::string strLearningClass;
	std::string strPlayerClass;
	int learningLevel;
	int playerLevel;
	double playerAttack;
	double playerDefense;
	double playerMagAttack;
	double playerMagDefense;
	double playerCharisma;
	double playerLuck;*/
public : 
	MainCharacter(std::string characterName, std::string characterType, std::string learnerClassName);
};

class AllyCharacter : QuestCharacter {

};

class AdvisorCharacter : QuestCharacter {

};

class CivilianCharacter : QuestCharacter {

};

class EnemyCharacter : QuestCharacter {


};

class Archer : MainCharacter {

};

class Knight : MainCharacter {

};

class Mage : MainCharacter {

};

#endif
