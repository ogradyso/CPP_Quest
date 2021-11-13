# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

project ("CPP_Quest")

# Include sub-projects.
add_subdirectory ("CPP_Quest")

target_compile_features(CPP_Quest PUBLIC cxx_std_20)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)