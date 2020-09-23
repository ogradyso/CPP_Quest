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
};


//character dialogue:
class QuestDialogue
{
public:
	QuestDialogue();


	void init(std::string);
	void destroyDialogue();

	void performDialogue();

private:
	std::vector<DialogueNode*> dialogueNodes;
};


//Lesson prompt:
class QuestLessonPrompt
{
public:
	QuestLessonPrompt();


	void init(std::string, std::string, std::string);
	void performDialogue();

private:
	std::vector<PromptNode*> promptSequence;
};