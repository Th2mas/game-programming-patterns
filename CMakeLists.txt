cmake_minimum_required(VERSION 3.19)

project(
        game-programming-patterns
        VERSION 1.0
        DESCRIPTION "Following the book examples of 'Game Programming Patterns' by Robert Nystrom"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Load 3rd party libraries
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
FetchContent_MakeAvailable(googletest)

add_subdirectory(command-pattern)
add_subdirectory(flyweight-pattern)
add_subdirectory(observer-pattern)
