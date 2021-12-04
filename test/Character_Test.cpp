#include "gtest/gtest.h"
#include "../CPP_Quest/QuestCharacter.h"
#include <tuple>
#include <boost/foreach.hpp>
#include <boost/range/combine.hpp>

TEST(CharacterTest, getters_tests) {
    //arrange
    std::tuple <std::string, std::string> lessonInfo;
    lessonInfo = std::make_tuple("Lesson1", "TheBasics");
    std::vector<std::string> testPrompts;
    std::vector<std::string> testAnswers;
    std::string prompt;
    std::string answer;
    std::string testPrompt;
    std::string testAnswer;
    testAnswers.push_back("1");
    testAnswers.push_back("2");
    testAnswers.push_back("3");
    testPrompts.push_back("Prompt1");
    testPrompts.push_back("Prompt2");
    testPrompts.push_back("Prompt3");

    //act
    QuestCharacter testCharacter = QuestCharacter("test", "Application Developer", "Archer", 4, lessonInfo);
    //assert
    EXPECT_EQ(testCharacter.getExp(), 4);

    testCharacter.getLessonInfo();
    EXPECT_EQ(testCharacter.getLearnerClass(), "Application Developer");
    EXPECT_EQ(testCharacter.getFighterClass(), "Archer");
    EXPECT_EQ(testCharacter.getName(), "test");
	EXPECT_EQ(testCharacter.getNextLessonTargetExp(),0);

    BOOST_FOREACH(boost::tie(prompt, answer, testPrompt, testAnswer), boost::combine(testCharacter.nextLessonPrompts, testCharacter.nextLessonAnswers, testPrompts, testAnswers))
    {
        EXPECT_EQ(prompt, testPrompt);
        EXPECT_EQ(answer, testAnswer);
    }
}

TEST(CharacterTest, setters_tests) {
    //arrange
    std::tuple <std::string, std::string> lessonInfo;
    lessonInfo = std::make_tuple("Lesson1", "TheBasics");
    std::tuple <std::string, std::string> testLessonInfo;
    testLessonInfo = std::make_tuple("Lesson1", "UserDefinedTypes");

    //act
    QuestCharacter testCharacter = QuestCharacter("test", "Application Developer", "Archer", 4, lessonInfo);
    testCharacter.setExp(4);
    testCharacter.setNextLesson();
    //assert

    EXPECT_EQ(testCharacter.getExp(), 8);
    EXPECT_EQ(testCharacter.getNextLesson(), testLessonInfo);
}