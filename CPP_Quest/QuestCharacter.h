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
public:
	std::string learnerClass;
	QuestCharacter();
	QuestCharacter(int);
	void getLessonInfo(const char*, const char*, const char*);
	int startNextLesson();
	int getExp();
	void setExp(int);
	bool saveProgress(std::string);
};


#endif
