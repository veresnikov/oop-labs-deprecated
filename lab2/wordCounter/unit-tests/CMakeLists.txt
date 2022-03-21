cmake_minimum_required(VERSION 3.20)
project(wordCounter)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        wordCounter_unit_tests
        tests.cpp
        ../src/wordCounter.cpp
)

add_custom_command(
        TARGET wordCounter_unit_tests
        POST_BUILD
        COMMAND wordCounter_unit_tests
)