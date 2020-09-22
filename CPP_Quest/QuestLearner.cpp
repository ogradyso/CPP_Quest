#include "QuestLearner.h"
#include "tinyxml2.h"


QuestLearner::QuestLearner()
{}

std::vector<std::string> QuestLearner::getLessonInfo() {
	tinyxml2::XMLDocument doc;
	doc.LoadFile("\GameFiles\LearnerLessons.xml");
	const char* lessonName = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->GetText();
	printf("Name of play (1): %s\n", title);
}

void QuestLearner :: startNextLesson() {

}