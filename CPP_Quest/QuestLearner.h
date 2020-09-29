#pragma once
#include "QuestDialogue.h"


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
	void startNextLesson();

};

#endif