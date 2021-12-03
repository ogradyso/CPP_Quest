#include "gtest/gtest.h"
#include "../CPP_Quest/QuestCharacter.h"
#include <tuple>

TEST(CharacterTest, test1) {
    //arrange
    std::tuple <std::string, std::string> lessonInfo;
    lessonInfo = std::make_tuple("Lesson1", "TheBasics");
    //act
    QuestCharacter testCharacter = QuestCharacter("test", "Application Developer", "Archer", 4, lessonInfo);
    //assert
    EXPECT_EQ(testCharacter.getExp(), 4);
    EXPECT_EQ(true, true);
}

//#include <gtest/gtest.h>
//
//TEST(HelloTest, BasicAssertions) {
//    EXPECT_STRNE("hello", "world");
//    EXPECT_EQ(7 * 6, 42);
//}