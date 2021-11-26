#include "QuestCharacter.h"
#include "tinyxml2.h"
#include <string>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/range/combine.hpp>
#include <array>
#include <filesystem>
#include <fstream>

const std::vector<std::string> lessonUnits{"TheBasics", "UserDefinedTypes", "Modularity", "Classes", "EssentialOperations",
"Templates", "ConceptsAndGenericProgramming","LibraryOverview", "StringsAndRegularExpressions", "InputAndOutput",
"Containers", "Algorithms", "Utilities", "Numerics", "Concurrency", "HistoryAndCompatability"};

QuestCharacter::QuestCharacter(std::string characterName, std::string characterLearnClass, std::string characterFightClass, int savedExperience, std::string nextLessonLevel, std::string nextLessonUnitName)
{
	this->learnerLevel = 0;
	this->nextLesson = nextLessonLevel;
	this->nextLessonAnswers;
	this->nextLessonUnit = nextLessonUnitName;
	this->nextLessonPrompts;
	this->totalExperience = savedExperience;
	this->name = characterName;
	this->learnerClass = characterLearnClass;
	this->fighterClass = characterFightClass;
	this->nextLessonTargetExp;
	std::vector<std::string> nextLessonAnswers;
}

QuestCharacter::QuestCharacter()
{
	this->learnerLevel = 0;
	this->nextLesson;
	this->nextLessonAnswers;
	this->nextLessonUnit;
	this->nextLessonPrompts;
	this->totalExperience = 0;
}

void QuestCharacter::getLessonInfo(const char* lessonRoot, const char* lessonLevel, const char* lessonFilePath)
{
	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(lessonFilePath);

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(lessonRoot);

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
	tinyxml2::XMLElement* expListElement = LessonRoot->FirstChildElement(lessonLevel)->FirstChildElement("LessonRewards")->FirstChildElement("Experience");
	this->nextLessonTargetExp = std::stoi(expListElement->GetText());

	eResult = xmlDoc.SaveFile(lessonFilePath);

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

int QuestCharacter::getNextLessonTargetExp() {
	return this->nextLessonTargetExp;
}
void QuestCharacter::setNextLesson() {
	std::filesystem::path lessonFilePath = std::filesystem::current_path().string() + "/QuestFiles/" + this->getNextLessonUnit() + ".xml";

	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(lessonFilePath.string().c_str());

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(this->getNextLessonUnit().c_str());

	tinyxml2::XMLNode* pListElement = LessonRoot->FirstChildElement(this->getNextLesson().c_str());

	tinyxml2::XMLNode* nextLessonElement = pListElement->NextSibling();
	
	if (nextLessonElement == nullptr) {
		this->setNextLessonUnit();
		this->nextLesson = "Lesson1";
	}
	else {
		this->nextLesson = nextLessonElement->Value();
	}

	eResult = xmlDoc.SaveFile(lessonFilePath.string().c_str());
}

std::string QuestCharacter::getNextLessonUnit() {
	return this->nextLessonUnit;
}

void QuestCharacter::setNextLessonUnit() {
	std::string currentLessonUnit = this->getNextLessonUnit();
	for (size_t i = 0; i < lessonUnits.size() - 1; ++i) {
		if (lessonUnits[i] == currentLessonUnit) {
			this->nextLessonUnit = lessonUnits[i + 1];
			break;
		}
	}
}