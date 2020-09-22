#pragma once
#include <string>
#include <iostream>
#include <vector>

//forward declaration of DialogueNode class
class PromptNode;
class DialogueNode;

class DialogueOption {
public:
	std::string text;
	DialogueNode *nextNode;
	int returnCode;
};

class PromptNode {
public:
	std::string promptText;
	std::string answerText;
	std::vector<PromptNode*> promptSequence;
};

class QuestDialogue
{
public:
	QuestDialogue();


	void init(std::string);
	void destroyDialogue();

	int performDialogue();

private:
	std::vector<DialogueNode*> dialogueNodes;
};

class QuestLessonPrompt
{
public:
	QuestLessonPrompt();


	void init(std::string, std::string, std::string);

private:
	std::vector<DialogueNode*> dialogueNodes;
};