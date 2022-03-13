cmake_minimum_required(VERSION 3.20)
project(vector)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        vector_unit_tests
        unit-tests/tests.cpp
        ../vector/vector.cpp
)

add_custom_command(
        TARGET vector_unit_tests
        POST_BUILD
        COMMAND vector_unit_tests
)

add_executable(
        vector
        main.cpp
        vector/vector.cpp
)

add_custom_command(
        TARGET vector
        POST_BUILD
        DEPENDS vector_unit_tests
        COMMAND ${PROJECT_SOURCE_DIR}/e2e-tests/run-e2e-tests.sh ${PROJECT_BINARY_DIR}/vector ${PROJECT_SOURCE_DIR}/e2e-tests/test-data
)
