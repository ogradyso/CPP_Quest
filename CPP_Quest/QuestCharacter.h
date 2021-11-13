#pragma once
#include <string>

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

class QuestLearner : QuestCharacter {
private:
	int learnerLevel;
	int totalExperience;
	int nextLesson;
	std::string nextLessonTitle;
	std::vector<std::string> nextLessonPrompts;
	std::vector<std::string> nextLessonAnswers;
public:
	std::string learnerClass;
	QuestLearner();
	QuestLearner(int);
	void getLessonInfo(const char*, const char*, const char*);
	int startNextLesson();
	int getExp();
	void setExp(int);
	bool saveProgress(std::string);
};

class MainCharacter : QuestLearner {
private:

public:
	MainCharacter();
	MainCharacter(std::string characterName, std::string characterType, int savedExperience);
};




#endif
