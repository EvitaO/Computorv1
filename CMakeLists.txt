cmake_minimum_required(VERSION 3.21.0)

project(computor)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

set(SOURCES
    ./src/main.cpp
    ./src/polynomial.cpp
    ./src/polynomial.hpp
    ./src/utils.cpp
    ./src/validate.cpp
    ./src/validate.hpp
    ./src/utils.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

add_subdirectory(test)
add_subdirectory(lib/googletest)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
