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

std::string leftTrim(std::string str, std::string chars)
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string rightTrim(std::string str, std::string chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string trimString(std::string str, std::string chars)
{
	return leftTrim(rightTrim(str, chars), chars);
}

QuestCharacter::QuestCharacter(std::string characterName, std::string characterLearnClass, std::string characterFightClass, int savedExperience, std::tuple <std::string, std::string> lessonInfo)
{
	this->learnerLevel = 0;
	this->nextLessonAnswers;
	this->nextLessonPrompts;
	this->totalExperience = savedExperience;
	this->name = characterName;
	this->learnerClass = characterLearnClass;
	this->fighterClass = characterFightClass;
	this->nextLessonTargetExp;
	this->lessonUnitTuple = lessonInfo;
	std::vector<std::string> nextLessonAnswers;
}

QuestCharacter::QuestCharacter()
{
	this->learnerLevel = 0;
	this->nextLessonAnswers;
	this->nextLessonPrompts;
	this->totalExperience = 0;
}

void QuestCharacter::getLessonInfo()
{
	tinyxml2::XMLDocument xmlDoc;
	std::tuple <std::string, std::string> lessonInfo = this->getNextLesson();
	std::filesystem::path lessonFilePath = std::filesystem::current_path().string() + "/QuestFiles/" + get<1>(lessonInfo) + ".xml";

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(lessonFilePath.string().c_str());

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(get<1>(lessonInfo).c_str());

	tinyxml2::XMLElement* pListElement = LessonRoot->FirstChildElement(get<0>(lessonInfo).c_str())->FirstChildElement("LessonPrompts")->FirstChildElement("Prompt");

	while (pListElement != nullptr)
	{
		const char* prompt = pListElement->GetText();
		std::string cleanPrompt = this->stringReplacement(prompt, "&gt;", ">");
		cleanPrompt = this->stringReplacement(cleanPrompt, "&lt;", "<").c_str();
		cleanPrompt = this->stringReplacement(cleanPrompt, "&amp;", "&").c_str();
		this->nextLessonPrompts.push_back(cleanPrompt);

		pListElement = pListElement->NextSiblingElement("Prompt");
	}

	pListElement = LessonRoot->FirstChildElement(get<0>(lessonInfo).c_str())->FirstChildElement("LessonAnswers")->FirstChildElement("Answer");

	while (pListElement != nullptr)
	{
		const char* answer = pListElement->GetText();
		std::string cleanAnswer = this->stringReplacement(answer, "&gt;", ">").c_str();
		cleanAnswer = this->stringReplacement(cleanAnswer, "&lt;", "<").c_str();
		cleanAnswer = this->stringReplacement(cleanAnswer, "&amp;", "&").c_str();
		this->nextLessonAnswers.push_back(cleanAnswer);

		pListElement = pListElement->NextSiblingElement("Answer");
	}
	tinyxml2::XMLElement* expListElement = LessonRoot->FirstChildElement(get<0>(lessonInfo).c_str())->FirstChildElement("LessonRewards")->FirstChildElement("Experience");
	this->nextLessonTargetExp = std::stoi(expListElement->GetText());

	eResult = xmlDoc.SaveFile(lessonFilePath.string().c_str());

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
std::tuple <std::string, std::string> QuestCharacter::getNextLesson() {
	return this->lessonUnitTuple;
}

int QuestCharacter::getNextLessonTargetExp() {
	return this->nextLessonTargetExp;
}
void QuestCharacter::setNextLesson() {
	std::tuple <std::string, std::string> lessonInfo = this->getNextLesson();
	std::filesystem::path lessonFilePath = std::filesystem::current_path().string() + "/QuestFiles/" + get<1>(lessonInfo) + ".xml";

	tinyxml2::XMLDocument xmlDoc;

	tinyxml2::XMLError eResult = xmlDoc.LoadFile(lessonFilePath.string().c_str());

	tinyxml2::XMLNode* LessonRoot = xmlDoc.FirstChildElement(get<1>(lessonInfo).c_str());

	tinyxml2::XMLNode* pListElement = LessonRoot->FirstChildElement(get<0>(lessonInfo).c_str());

	tinyxml2::XMLNode* nextLessonElement = pListElement->NextSibling();
	
	if (nextLessonElement == nullptr) {
		std::string currentLessonUnit = get<1>(this->lessonUnitTuple);
		for (size_t i = 0; i < lessonUnits.size() - 1; ++i) {
			if (lessonUnits[i] == currentLessonUnit) {
				get<1>(this->lessonUnitTuple) = lessonUnits[i + 1];
				break;
			}
		}
		get<0>(this->lessonUnitTuple) = "Lesson1";
	}
	else {
		get<0>(this->lessonUnitTuple) = nextLessonElement->Value();
	}

	eResult = xmlDoc.SaveFile(lessonFilePath.string().c_str());
}

std::string QuestCharacter::stringReplacement(std::string str, const std::string from, const std::string to) {
	if (from.empty())
		return str;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
	return trimString(str, " ");
}