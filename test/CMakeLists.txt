cmake_minimum_required (VERSION 3.10)

include(CTest)

set(BOOST_ROOT "C:\\boost") # either set it here or from the command line  

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED) # header only libraries must not be added here

# Add source to this project's executable.

set(BINARY ${CMAKE_PROJECT_NAME})

#add_executable(CPP_Quest_Test CharacterTest.cpp ../CPP_Quest/QuestCharacter.cpp ../CPP_Quest/QuestCharacter.h ../CPP_Quest/tinyxml2.cpp ../CPP_Quest/tinyxml2.h)

#add_test(NAME CharacterTest COMMAND CharacterTest)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})


target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)


#used this before
#add_executable(CPP_Quest_Test CharacterTest.cpp ../CPP_Quest/QuestCharacter.cpp ../CPP_Quest/QuestCharacter.h ../CPP_Quest/tinyxml2.cpp ../CPP_Quest/tinyxml2.h)
#add_test(NAME CharacterTest COMMAND CharacterTest)


#target_include_directories(CPP_Quest_Test PUBLIC ${Boost_INCLUDE_DIRS}) 
#target_link_libraries(CPP_Quest_Test ${Boost_LIBRARIES})

# TODO: Add tests and install targets if needed.

target_compile_features(CPP_Quest_Test PUBLIC cxx_std_20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
