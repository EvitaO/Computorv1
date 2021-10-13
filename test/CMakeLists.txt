
set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SOURCES 
    main.cpp
    sqrt_test.cpp
    gcd_test.cpp
    getdegree_test.cpp
    getreduced_test.cpp
    setup_test.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(
    NAME ${BINARY}
    COMMAND ${BINARY}
)

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)