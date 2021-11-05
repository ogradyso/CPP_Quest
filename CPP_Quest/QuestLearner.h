#pragma once
#include <string>
#include <vector>

#ifndef QuestLearner_H
#define QuestLearner_H

class QuestLearner {
private:
	int learnerLevel;
	int nextLesson;
	std::string nextLessonTitle;
	std::vector<std::string> nextLessonPrompts;
	std::vector<std::string> nextLessonAnswers;
public: 
	std::string learnerClass;
	QuestLearner();
	void getLessonInfo(const char*, const char*, const char*);
	int startNextLesson();

};

#endif