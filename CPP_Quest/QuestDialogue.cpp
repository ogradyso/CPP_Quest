#include "QuestDialogue.h">
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>


QuestDialogue::QuestDialogue()
{

}

//set up the dialogue tree:
void QuestDialogue::init(std::string lessonDialogue) {
	//split string based on delimiter patter using regex patterm matching:
	std::vector<std::string> prompts;
	boost::split(prompts, lessonDialogue, boost::is_any_of("_"));
	for (auto& prompt : prompts)
	{

	}
}

void QuestDialogue::destroyDialogue() {

}

int QuestDialogue::performDialogue() {

}
