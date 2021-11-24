#include "QuestCharacter.h"
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/range/combine.hpp>
#include <array>
#include <filesystem>
#include <fstream>

QuestCharacter::QuestCharacter(std::string characterName, std::string characterLearnClass, std::string characterFightClass, int savedExperience, std::string nextLessonLevel)
{
	this->learnerLevel = 0;
	this->nextLesson = nextLessonLevel;
	this->nextLessonAnswers;
	this->nextLessonTitle;
	this->nextLessonPrompts;
	this->totalExperience = savedExperience;
	this->name = characterName;
	this->learnerClass = characterLearnClass;
	this->fighterClass = characterFightClass;
}

QuestCharacter::QuestCharacter()
{
	this->learnerLevel = 0;
	this->nextLesson;
	this->nextLessonAnswers;
	this->nextLessonTitle;
	this->nextLessonPrompts;
	this->totalExperience = 0;
}

void QuestCharacter::getLessonInfo(const char* lessonRoot, const char* lessonLevel, const char* lessonFilePath)
{
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(lessonFilePath);

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(lessonRoot);

	tinyxml2::XMLElement* pLessonTitleElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonTitle");
	const char* plessonTitle = pLessonTitleElement->GetText();
	std::string strTitle{ plessonTitle };
	this->nextLessonTitle = strTitle;

	tinyxml2::XMLElement* pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");

	while (pListElement != nullptr)
	{
		const char* prompt = pListElement->GetText();

		this->nextLessonPrompts.push_back(prompt);

		pListElement = pListElement->NextSiblingElement("Prompt");
	}

	pListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonAnswers")->FirstChildElement("Answer");

	while (pListElement != nullptr)
	{
		const char* answer = pListElement->GetText();
		this->nextLessonAnswers.push_back(answer);

		pListElement = pListElement->NextSiblingElement("Answer");
	}

};

int QuestCharacter::startNextLesson() {
	int expPoints = 0;
	std::string lessonAnswerFile = std::filesystem::current_path().string() + "/LessonAnswers/LessonAnswer.cpp";;
	std::string answer;
	std::string prompt;
	std::string correctAnswer;

	std::fstream output_fstream;

	std::filesystem::remove(lessonAnswerFile);
	output_fstream.open(lessonAnswerFile, std::ios_base::out);

	BOOST_FOREACH(boost::tie(prompt, correctAnswer), boost::combine(this->nextLessonPrompts, this->nextLessonAnswers))
	{
		std::cout << prompt << '\n';
		std::string response;
		getline(std::cin, response);
		if (response == correctAnswer) {
			expPoints++;
		}
		if (response != "OK") {
			output_fstream << response << '\n';
		}

	}
	output_fstream.close();

	this->nextLessonPrompts.clear();
	this->nextLessonAnswers.clear();

	return expPoints;

}

int QuestCharacter::getExp() {
	return this->totalExperience;
}

void QuestCharacter::setExp(int expGained) {
	this->totalExperience += expGained;
}

std::string QuestCharacter::getLearnerClass() {
	return this->learnerClass;
}

std::string QuestCharacter::getFighterClass() {
	return this->fighterClass;
}
std::string QuestCharacter::getName() {
	return this->name;
}
std::string QuestCharacter::getNextLesson() {
	return this->nextLesson;
}
void QuestCharacter::setNextLesson(std::string nextLessonLevel) {
	this->nextLesson = nextLessonLevel;
}