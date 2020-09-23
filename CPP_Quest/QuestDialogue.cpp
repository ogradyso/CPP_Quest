#include "QuestDialogue.h">
#include <string>
#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>


QuestDialogue::QuestDialogue()
{

}

QuestLessonPrompt::QuestLessonPrompt()
{

}

//set up the dialogue tree:
void QuestDialogue::init(std::string strDialogue) {
	////split string based on delimiter patter using regex patterm matching:
	//std::vector<std::string> prompts;
	//std::vector<std::string> answers;
	//boost::split(prompts, lessonDialogue, boost::is_any_of("_"));
	//boost::split(answers, lessonAnswers, boost::is_any_of("_"));
	//PromptNode* head = new PromptNode;
	//PromptNode* next = new PromptNode;
	//PromptNode* third = new PromptNode;
	//head->promptText = "You are about to start lesson " + lessonName;
	//head->answerText = "Yes";
	//head->promptSequence = next;
	//next->promptSequence = third;
	////index based for loop to add a node:
	//for (size_t i = 0; i < prompts.size(); i++)
	//{
	//	next->promptText = prompts[i];
	//	next->answerText = answers[i];
	//	next = next->promptSequence;
	//	if (i < prompts.size() - 1)
	//	{
	//		third = new PromptNode;
	//		next->promptSequence = third;
	//	}
	//	else if (i == prompts.size() - 1)
	//	{
	//		next->promptSequence = nullptr;
	//	}
	//}
}

void QuestDialogue::destroyDialogue() {

}

void QuestDialogue::performDialogue() {

}

//set up the prompt sequence:
void QuestLessonPrompt::init(std::string lessonName, std::string lessonDialogue, std::string lessonAnswers) {
	//split string based on delimiter patter using regex patterm matching:
	std::vector<std::string> prompts;
	std::vector<std::string> answers;
	boost::split(prompts, lessonDialogue, boost::is_any_of("_"));
	boost::split(answers, lessonAnswers, boost::is_any_of("_"));
	PromptNode* head = new PromptNode;
	PromptNode* next = new PromptNode;
	head->promptText = "You are about to start lesson: " + lessonName + "Type \'Yes\' to confirm";
	head->answerText = "Yes";
	this->promptSequence.push_back(head);
	//push each prompt node:
	for (size_t i = 0; i < prompts.size(); i++)
	{
		next->promptText = prompts[i];
		next->answerText = answers[i];
		this->promptSequence.push_back(next);
		if (i < prompts.size() - 1) {
			next = new PromptNode;
		}
	}
}

//present lesson:
void QuestLessonPrompt::performDialogue() {
	std::string playerResponse;
	for (auto lessonPrompt : this->promptSequence) 
	{
		std::cout << lessonPrompt->promptText;
		std::cin >> playerResponse;
		while (playerResponse != lessonPrompt->answerText) 
		{
			std::cout << "Please try again. " + lessonPrompt->promptText;
			std::cin >> playerResponse;
		}


	}
	std::cout << "Congratulations, the lesson is complete!";
}



