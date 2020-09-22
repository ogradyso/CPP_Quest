#pragma once
#include "QuestDialogue.h"

#ifndef QuestLearner_H
#define QuestLearner_H

class QuestLearner {
private:
	int learnerLevel;
	int nextLesson;
public: 
	std::vector<std::string> getLessonInfo();
	void startNextLesson();

};

#endif