#pragma once
#include <iostream>
#include "QuestGame.h"
#include "QuestCharacter.h"
#include "tinyxml2.h"
#include "tinyxml2.cpp"
#include <regex>
#include <filesystem>
#include <fstream>

//#define CATCH_CONFIG_MAIN
//#include "catch.h"

bool checkForGameFile(std::string fileName) {
	std::string gameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + fileName + ".xml";
	std::filesystem::path testPath{gameFilePath};
	if (exists(testPath)) {
		return true;
	}
	else {
		return false;
	}
}

std::string inputValidation(std::string strPatternOfOptions, std::string promptToUser, std::string followUpPrompt) {
	std::string userInput;
	std::regex patternOfOptions{ (strPatternOfOptions) };
	std::cout << promptToUser;
	std::cin >> userInput;
	while (true) {
		if (std::regex_match(userInput, patternOfOptions)) {
			return userInput;
		}
		else {
			std::cout << followUpPrompt;
			std::cin >> userInput;
		}
	}
}

std::filesystem::path CreateNewGameFile(std::string playerName, std::string learningClass, std::string characterClass) {
	const char* initExp = "0";
	std::string strGameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + playerName + ".xml";
	auto ptrGameFilePath = strGameFilePath.c_str();
	//create a document:
	tinyxml2::XMLDocument xmlDoc;
	//add an element (int)
	tinyxml2::XMLNode* pRoot = xmlDoc.NewElement("GameFile");
	xmlDoc.InsertFirstChild(pRoot);
	tinyxml2::XMLElement* pPlayerElement = xmlDoc.NewElement("PlayerOne");
	pPlayerElement->SetAttribute("PlayerName", playerName.c_str());
	pPlayerElement->SetAttribute("LearningClass", learningClass.c_str());
	pPlayerElement->SetAttribute("CharacterClass", characterClass.c_str());
	pPlayerElement->SetAttribute("CurrentExp", initExp);

	pRoot->InsertEndChild(pPlayerElement);

	tinyxml2::XMLError eResult = xmlDoc.SaveFile(ptrGameFilePath);
	std::filesystem::path gameFilePath{ strGameFilePath };
	return gameFilePath;

}

void StartGame(void) {
	std::string playerName;
	std::cout << "What is your name?" << '\n';
	std::cin >> playerName;
	std::cout << '\n';
	std::string learningClass = inputValidation("[H|A|L|N|W]", "Which learning class would you like to choose? \n(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard\n", "You must choose an upper case letter associated with a learning class:\n(H)obbyist; (A)pplication Developer; (L)ibrary Developer; (N)etwork Specialist; (W)izard\n");
	
	if (learningClass == "H") {
		learningClass = "Hobbyist";
	}
	else if (learningClass == "A") {
		learningClass = "Application developer";
	}
	else if (learningClass == "L") {
		learningClass = "Library developer";
	}
	else if (learningClass == "N") {
		learningClass = "Network developer";
	}
	else if (learningClass == "W") {
		learningClass = "Wizard";
	}
	std::string playerClass = inputValidation("[A|K|M]", "Which player class would you like to choose? \n(A)rcher; (K)night; (M)age\n", "You must choose an upper case letter associated with a player class:\n(A)rcher; (K)night; (M)age\n");	
	
	if (playerClass == "A") {
		playerClass = "Archer";
	}
	else if (playerClass == "K") {
		playerClass = "Knight";
	}
	else if (playerClass == "M") {
		playerClass = "Mage";
	}

	if (!checkForGameFile(playerName)) {
		std::filesystem::path gameFilePath = CreateNewGameFile(playerName, learningClass, playerClass);
		QuestGame NowPlaying{gameFilePath};
		NowPlaying.StartGame();
	}
	else {
		std::cout << "It looks like a game file with this name already exists.\n";
		std::string userPromptLoadGame = inputValidation("[Y|N]", "Would you like to load the game : " + playerName + " ? \n", "You have to choose either Y for Yes or N for No.");
		if (*userPromptLoadGame.begin() = 'Y') {
			std::string strGameFilePath = std::filesystem::current_path().string() + "/GameFiles/" + playerName + ".xml";
			std::filesystem::path gameFilePath{ strGameFilePath };
			QuestGame NowPlaying{ gameFilePath };
			NowPlaying.StartGame();
		}
		else {
			std::cout << "Okay, exiting the game.";
		}
	}
	std::cout << '\n';
}

void LoadGame(std::string gameFilePath) {
	QuestGame CurrentGame = QuestGame(gameFilePath);

}

int main() {
	std::cout << "  QQ     UU  UU  EEEEEE    SS    TTTTTT  " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE      SS  SS    TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EEEEEE   SS       TT    " << '\n';
	std::cout << "QQ  QQ   UU  UU  EE         SS     TT    " << '\n';
	std::cout << "  QQ     UUUUUU  EE      SS  SS    TT    " << '\n';
	std::cout << "   QQQ    UUUU   EEEEEE    SS      TT    " << '\n' << '\n';
	std::cout << "You have chosen to embark on an epic journey!" << "\n\n";
	std::string startChoice = inputValidation("[L|S|E]", "Would you like to (L)oad a saved Quest, (S)tart a new Quest, or (E)xit the game and return to the command line?\n", "You will need to enter either an L for Load, an S for Start or an E for Exit.\n");

	switch (*startChoice.begin()) {
	case 'L':
		std::cout << "Okay, which game would you like to load?" << '\n';
		std::cout << "Feature broken at this time. Exiting." << '\n';
		break;
	case 'S':
		std::cout << "Very well, we shall prepare for our journey!" << '\n';
		for (int i = 0; i <= 30;i++) {
			std::cout << '\n';
		}
		StartGame();
		break;
	case 'E':
		std::cout << "Its probably for the best, come back when you are ready. We'll be here!" << '\n';
		return 1;
	default:
		return 1;
	}

}

//TEST_CASE("CreateNewGameFile ") {
//	SECTION("returns a file path for an xml document with the name of the player in the game files location") {
//		std::string correctFilePathString = std::filesystem::current_path().string() + "/GameFiles/test1.xml";
//		std::filesystem::path returnedFilePath = CreateNewGameFile("test1", "test1", "test1");
//		REQUIRE(returnedFilePath.string() == correctFilePathString);
//		if (returnedFilePath.string() == correctFilePathString) {
//			remove(correctFilePathString.c_str());
//		}
//		else {
//			std::cout << "Did not remove";
//		}
//	}
//	SECTION("contains correct initialized player one data") {
//		std::string correctFilePathString = std::filesystem::current_path().string() + "/GameFiles/test2.xml";
//		std::filesystem::path returnedFilePath = CreateNewGameFile("test2", "test2", "test2");
//		tinyxml2::XMLDocument xmlDoc;
//		tinyxml2::XMLError eResult = xmlDoc.LoadFile(correctFilePathString.c_str());
//		tinyxml2::XMLNode* GameFileRoot = xmlDoc.FirstChild();
//		REQUIRE(GameFileRoot != nullptr);
//		if (GameFileRoot != nullptr) {
//			tinyxml2::XMLElement* GameFileElement = GameFileRoot->FirstChildElement("PlayerOne");
//			REQUIRE(GameFileElement != nullptr);
//			const char* playerNameAttributeText = nullptr;
//			const char* learnerClassAttributeText = nullptr;
//			const char* characterClassAttributeText = nullptr;
//
//			playerNameAttributeText = GameFileElement->Attribute("PlayerName");
//			learnerClassAttributeText = GameFileElement->Attribute("LearningClass");
//			characterClassAttributeText = GameFileElement->Attribute("CharacterClass");
//
//			REQUIRE(playerNameAttributeText != nullptr);
//
//			REQUIRE(learnerClassAttributeText != nullptr);
//			REQUIRE(characterClassAttributeText != nullptr);
//
//			if (playerNameAttributeText != nullptr && learnerClassAttributeText != nullptr && characterClassAttributeText != nullptr) {
//				std::string strOutPlayerName = playerNameAttributeText;
//				REQUIRE(strOutPlayerName == "test2");
//				std::string strOutLearnerClass = learnerClassAttributeText;
//				REQUIRE(strOutLearnerClass == "test2");
//				std::string strOutCharacterClass = characterClassAttributeText;
//				REQUIRE(strOutCharacterClass == "test2");
//				if (strOutCharacterClass == "test2") {
//					remove(correctFilePathString.c_str());
//				}
//				else {
//					std::cout << "Did not remove";
//				}
//			}
//		}
//	}
//}