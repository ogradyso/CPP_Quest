#pragma once
#include <string>
#include "QuestLearner.h"

#ifndef QuestCharacter_H
#define QuestCharacter_H

class QuestCharacter {

protected:
	std::string characterName;
	std::string characterType;
public:
	QuestCharacter();
	QuestCharacter(std::string characterName, std::string characterType);
};

class MainCharacter : QuestCharacter {
private :
	QuestLearner learner;

public : 
	MainCharacter();
	MainCharacter(std::string characterName, std::string characterType);
};


#endif
