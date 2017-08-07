cmake_minimum_required(VERSION 3.0.2)
project(median_calculator)
enable_testing()

set (CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(test)
add_subdirectory(test_generator)

file(GLOB SOURCES src/*.cpp)
include_directories("include")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic" )

add_executable(median_calculator ${SOURCES})
