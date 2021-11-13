# CMakeList.txt : CMake project for CPP_Quest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Add source to this project's executable.

add_executable (CPP_Quest "CPP_Quest.cpp" "CPP_Quest.h" "GameLoader.cpp" "GameLoader.h" "QuestCharacter.cpp" "QuestCharacter.h" "QuestGame.cpp" "QuestGame.h" "tinyxml2.cpp" "tinyxml2.h")

# TODO: Add tests and install targets if needed.

target_compile_features(CPP_Quest PUBLIC cxx_std_20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)