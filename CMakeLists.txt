cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME my_array)
project(${PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_executable(my_array main.cpp include/my_array.h)

enable_testing()

add_subdirectory(tests)