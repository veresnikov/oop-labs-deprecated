cmake_minimum_required(VERSION 3.20)
project(wordCounter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(unit-tests)

add_executable(
        wordCounter
        main.cpp
        src/wordCounter.cpp
)

add_custom_command(
        TARGET wordCounter
        POST_BUILD
        COMMAND ${PROJECT_SOURCE_DIR}/e2e-tests/run-e2e-tests.sh ${PROJECT_BINARY_DIR}/wordCounter ${PROJECT_SOURCE_DIR}/e2e-tests/test-data
)
