#include "QuestLearner.h"
#include "tinyxml2.h"
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/range/combine.hpp>
#include <array>
#include <filesystem>
#include <fstream>


QuestLearner::QuestLearner(int savedExperience)
{
	this->learnerLevel = 0;
	this->nextLesson = 0;
	this->nextLessonAnswers;
	this->nextLessonTitle;
	this->nextLessonPrompts;
	this->totalExperience = savedExperience;
}

QuestLearner::QuestLearner()
{
	this->learnerLevel = 0;
	this->nextLesson = 0;
	this->nextLessonAnswers;
	this->nextLessonTitle;
	this->nextLessonPrompts;
	this->totalExperience = 0;
}


void QuestLearner::getLessonInfo(const char* lessonRoot, const char* lessonLevel, const char* lessonFilePath)
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

int QuestLearner :: startNextLesson() {
	int expPoints = 0;
	std::string lessonAnswerFile = std::filesystem::current_path().string() + "\\LessonAnswers\\LessonAnswer.cpp";;
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

	return expPoints;

}

int QuestLearner :: getExp() {
	return this->totalExperience;
}

void QuestLearner :: setExp(int expGained) {
	this->totalExperience += expGained;
}

bool saveProgress(std::string gamefilePath) {
	//auto ptrGameFilePath = gamefilePath.c_str();
	////create a document:
	//tinyxml2::XMLDocument xmlDoc;
	////add an element (int)
	//tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("GameFile");
	//xmlDoc.InsertFirstChild(pRoot);
	//tinyxml2::XMLElement* pPlayerElement = xmlDoc.NewElement("PlayerOne");
	//pPlayerElement->SetAttribute("PlayerName", playerName.c_str());
	//pPlayerElement->SetAttribute("LearningClass", learningClass.c_str());
	//pPlayerElement->SetAttribute("CharacterClass", characterClass.c_str());

	//pRoot->InsertEndChild(pPlayerElement);

	//tinyxml2::XMLError eResult = xmlDoc.SaveFile(ptrGameFilePath);
	//std::filesystem::path gameFilePath{ strGameFilePath };
	//return gameFilePath;
	return true;
}