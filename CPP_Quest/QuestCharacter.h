#pragma once
#include <string>
#include <vector>

#ifndef QuestCharacter_H
#define QuestCharacter_H

class QuestCharacter {
private:
	int learnerLevel;
	int totalExperience;
	int nextLesson;
	std::string nextLessonTitle;
	std::vector<std::string> nextLessonPrompts;
	std::vector<std::string> nextLessonAnswers;
	std::string name;
	std::string learnerClass;
	std::string fighterClass;
public:
	QuestCharacter();
	QuestCharacter(std::string, std::string, std::string, int);
	void getLessonInfo(const char*, const char*, const char*);
	int startNextLesson();
	int getExp();
	void setExp(int);
	std::string getLearnerClass();
	std::string getFighterClass();
	std::string getName();
};


#endif
