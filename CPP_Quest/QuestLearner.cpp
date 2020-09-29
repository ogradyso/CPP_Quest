#include "QuestLearner.h"
#include "tinyxml2.h"


QuestLearner::QuestLearner()
{
	this->learnerLevel = 0;
	this->nextLesson = 0;
	this->nextLessonAnswers;
	this->nextLessonTitle;
	this->nextLessonPrompts;
}

void QuestLearner::getLessonInfo(const char* lessonRoot, const char* lessonLevel, const char* gameFilePath)
{
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(gameFilePath);

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(lessonRoot);

	tinyxml2::XMLElement* pLessonTitleElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonTitle");
	const char* plessonTitle = pLessonTitleElement->GetText();
	std::string strTitle{ plessonTitle };
	this->nextLessonTitle = strTitle;

	tinyxml2::XMLElement* pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");

	while (pListElement != nullptr)
	{
		const char* prompt = pListElement->GetText();
		std::string strPrompt{ prompt };

		this->nextLessonPrompts.push_back(prompt);

		pListElement = pListElement->NextSiblingElement("Prompt");
	}

	pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonAnswers")->FirstChildElement("Answer");

	while (pListElement != nullptr)
	{
		const char* answer = pListElement->GetText();
		std::string strPrompt{ answer };

		this->nextLessonAnswers.push_back(answer);

		pListElement = pListElement->NextSiblingElement("Answer");
	}

};

void QuestLearner :: startNextLesson() {

}