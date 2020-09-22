#include "QuestDialogue.h">
#include <string>
#include <vector>
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
	//boost::split(prompts, lessonDialogue, boost::is_any_of("_"));
	//DialogueNode* head = new DialogueNode;
	//DialogueNode* next = new DialogueNode;
	//head->text = "You are about to start lesson " + lessonName;
	//head->dialogueOptions.push_back(next);
	//for (auto& prompt : prompts)
	//{
	//	next->text = prompt;
	//}
}

//set up the dialogue tree:
void QuestLessonPrompt::init(std::string lessonName, std::string lessonDialogue, std::string lessonAnswers) {
	//split string based on delimiter patter using regex patterm matching:
	std::vector<std::string> prompts;
	std::vector<std::string> answers;
	boost::split(prompts, lessonDialogue, boost::is_any_of("_"));
	boost::split(answers, lessonDialogue, boost::is_any_of("_"));
	PromptNode* head = new PromptNode;
	PromptNode* next = new PromptNode;
	head->promptText = "You are about to start lesson " + lessonName;
	head->answerText = "Yes";
	head->promptSequence.push_back(next);
	for (size_t i = 0; i < prompts.size(); i++)
	{
		next->promptText = prompts[i];
		next->answerText = answers[i];
	}
}

void QuestDialogue::destroyDialogue() {

}

int QuestDialogue::performDialogue() {

}


