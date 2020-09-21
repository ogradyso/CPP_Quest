#pragma once
#include <string>
#include <iostream>
#include <vector>

//forward declaration of DialogueNode class
class DialogueNode;

class DialogueOption {
public:
	std::string text;
	DialogueNode *nextNode;
	int returnCode;
};

class DialogueNode {
public:
	std::string text;
	std::vector<DialogueOption> dialogueOptions;
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