cmake_minimum_required(VERSION 3.21.0)

project(computer)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(SOURCE_FILES 
    main.cpp
    polynomial.cpp
    utils.cpp
    validate.cpp
)

add_executable(computer ${SOURCE_FILES})

include(googletest)

add_subdirectory(googletest)

target_link_libraries(computer PUBLIC gtest_main)

enable_testing()

add_subdirectory(test)
