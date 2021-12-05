cmake_minimum_required (VERSION 3.10)

if (UNIX)
	set(BOOST_ROOT /usr/include)
	set(Boost_INCLUDE_DIR /usr/include)
    set(boost_combine_DIR /usr/include/boost/range)
	target_compile_features(CPP_Quest PUBLIC cxx_std_20)

	# specify the C++ standard
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED True)

	target_link_libraries(CPP_Quest stdc++fs)
else (UNIX)
	set(BOOST_ROOT "C:\\boost") # either set it here or from the command line  
endif (UNIX)


set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED) # header only libraries must not be added here

# Add source to this project's executable.

#add_test(NAME CharacterTest COMMAND CharacterTest)

#enable_testing()
#include_directories(${GTEST_INCLUDE_DIRS})

# Unit Tests
# Add test cpp file

# Link test executable against gtest & gtest_main

#add_executable(CPP_Quest_Test Character_Test.cpp ../CPP_Quest/QuestCharacter.cpp ../CPP_Quest/QuestCharacter.h ../CPP_Quest/tinyxml2.cpp ../CPP_Quest/tinyxml2.h)

#target_link_libraries(CPP_Quest_Test gtest)
#target_include_directories(CPP_Quest_Test PUBLIC ${Boost_INCLUDE_DIRS}) 
#target_link_libraries(CPP_Quest_Test ${Boost_LIBRARIES})

#target_link_libraries(CPP_Quest_Test ${GTEST_BOTH_LIBRARIES})
#add_test(NAME CharacterTest COMMAND CharacterTest)


#used this before
#add_test(NAME CharacterTest COMMAND CharacterTest)

# TODO: Add tests and install targets if needed.

#target_compile_features(CPP_Quest_Test PUBLIC cxx_std_20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#cmake_minimum_required(VERSION 3.14)

#set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/bb9216085fbbf193408653ced9e73c61e7766e80.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#add_executable(
#  CPP_Quest_Test
#  hello_test.cc
#)

add_executable(CPP_Quest_Test 
	"Character_Test.cpp"
	"GameLoader_Test.cpp"
	"QuestGame_Test.cpp"
	"../CPP_Quest/QuestCharacter.cpp"
	"../CPP_Quest/QuestCharacter.h" 
	"../CPP_Quest/GameLoader.cpp" 
	"../CPP_Quest/GameLoader.h" 
	"../CPP_Quest/tinyxml2.cpp" 
	"../CPP_Quest/tinyxml2.h" 
	"QuestGame_Test.cpp"
)

target_link_libraries(
  CPP_Quest_Test
  gtest_main
)

target_include_directories(CPP_Quest_Test PUBLIC ${Boost_INCLUDE_DIRS}) 
target_link_libraries(CPP_Quest_Test ${Boost_LIBRARIES})


include(GoogleTest)
gtest_discover_tests(CPP_Quest_Test)
