#include <filesystem>
#include "gtest/gtest.h"
#include "../CPP_Quest/GameLoader.h"
#include "../CPP_Quest/QuestCharacter.h"

class GameLoaderTest : public ::testing::Test {
protected:
    std::string strGameFilePath;
    std::filesystem::path testPath;
    GameLoader testLoader;
    void SetUp() override {
        this->strGameFilePath = std::filesystem::current_path().string() + "/GameFiles/test.xml";
        std::filesystem::path tempTestPath{ this->strGameFilePath };
        this->testPath = tempTestPath;
        //act
        this->testLoader = GameLoader();
    }

    void TearDown() override {
        std::filesystem::remove(this->testPath);
    }
};

TEST_F(GameLoaderTest, createNewGameFileTest) {
    //arrange
    //act
    GameLoader testLoader = GameLoader();
    //assert
    EXPECT_EQ(std::filesystem::exists(testPath), false);
    testLoader.CreateNewGameFile("test", "Application Developer", "Archer");
    EXPECT_EQ(std::filesystem::exists(testPath), true);
}

TEST_F(GameLoaderTest, loadGameFileTest) {
    //arrange
    std::tuple <std::string, std::string> lessonInfo;
    lessonInfo = std::make_tuple("Lesson1", "TheBasics");
    //act
    QuestCharacter testCharacter = QuestCharacter("test", "Application Developer", "Archer", 4, lessonInfo);
    testLoader.setGameFilePath(strGameFilePath);
    testLoader.CreateNewGameFile("test", "Application Developer", "Archer");
    //assert
    EXPECT_EQ(testLoader.getGameFilePath(), strGameFilePath);
    QuestCharacter testCharacterA = testLoader.LoadGameFile();
    EXPECT_EQ(testCharacterA.getName(), testCharacter.getName());
}

TEST_F(GameLoaderTest, saveGameFileTest) {
    ///arrange
    testLoader.setGameFilePath(strGameFilePath);
    testLoader.CreateNewGameFile("test", "Application Developer", "Archer");
    QuestCharacter testCharacterA = testLoader.LoadGameFile();
    testCharacterA.setExp(4);
    //act
    testLoader.saveProgress(testCharacterA);
    QuestCharacter testCharacterB = testLoader.LoadGameFile();
    //assert
    EXPECT_EQ(testCharacterB.getExp(), testCharacterA.getExp());
}