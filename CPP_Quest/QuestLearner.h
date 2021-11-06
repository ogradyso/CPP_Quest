#pragma once
#include <string>
#include <vector>

#ifndef QuestLearner_H
#define QuestLearner_H

class QuestLearner {
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
	bool saveProgress();
};

#endif