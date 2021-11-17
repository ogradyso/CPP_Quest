# CMakeList.txt : CMake project for CPP_Quest, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)


if (UNIX)
	set(BOOST_ROOT $HOME/boost)
	set(Boost_INCLUDE_DIR $HOME/boost)
    set(boost_combine_DIR $HOME/boost/range)
else (UNIX)
	set(BOOST_ROOT "C:\\boost") # either set it here or from the command line  
endif (UNIX)


set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED) # header only libraries must not be added here

# Add source to this project's executable.

add_executable (CPP_Quest "CPP_Quest.cpp" "CPP_Quest.h" "GameLoader.cpp" "GameLoader.h" "QuestCharacter.cpp" "QuestCharacter.h" "QuestGame.cpp" "QuestGame.h" "tinyxml2.cpp" "tinyxml2.h")

target_include_directories(CPP_Quest PUBLIC ${Boost_INCLUDE_DIRS}) 
target_link_libraries(CPP_Quest ${Boost_LIBRARIES})

# TODO: Add tests and install targets if needed.

target_compile_features(CPP_Quest PUBLIC cxx_std_20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)