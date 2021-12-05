#pragma once
#include <string>
#include <vector>
#include <tuple>

#ifndef QuestCharacter_H
#define QuestCharacter_H

class QuestCharacter {
private:
	int learnerLevel;
	int totalExperience;
	int nextLessonTargetExp;
	std::string name;
	std::string learnerClass;
	std::string fighterClass;
	std::tuple < std::string, std::string> lessonUnitTuple;
	
public:
	std::vector<std::string> nextLessonPrompts;
	std::vector<std::string> nextLessonAnswers;
	QuestCharacter();
	QuestCharacter(std::string, std::string, std::string, int, std::tuple <std::string, std::string>);
	void getLessonInfo();
	int startNextLesson();
	int getExp();
	void setExp(int);
	std::string getLearnerClass();
	std::string getFighterClass();
	std::string getName();
	std::tuple <std::string, std::string> getNextLesson();
	void setNextLesson();
	int getNextLessonTargetExp();
	std::string stringReplacement(std::string, std::string, std::string);
};


#endif
