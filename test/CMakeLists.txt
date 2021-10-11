
cmake_minimum_required(VERSION 3.21.0)

# add_subdirectory(${CMAKE_BINARY_DIR}/googletest)

add_executable(computertest sqrt_test.cpp)

# include_directories(../googletest)


target_link_libraries(gtest_main)

add_test(
    NAME roottest
    COMMAND computer
)