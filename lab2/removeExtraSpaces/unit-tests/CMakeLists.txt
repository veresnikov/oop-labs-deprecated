cmake_minimum_required(VERSION 3.20)
project(removeExtraSpaces)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        removeExtraSpaces_tests
        tests.cpp
        ../src/StringsFunction.cpp
)

add_custom_command(
        TARGET removeExtraSpaces_tests
        POST_BUILD
        COMMAND removeExtraSpaces_tests
)
