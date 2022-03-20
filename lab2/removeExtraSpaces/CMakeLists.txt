cmake_minimum_required(VERSION 3.20)
project(removeExtraSpaces)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(unit-tests)

add_executable(
        removeExtraSpaces
        main.cpp
        src/StringsFunction.cpp
)
